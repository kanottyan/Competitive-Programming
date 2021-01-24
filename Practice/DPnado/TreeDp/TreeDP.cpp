//https://hcpc-hokudai.github.io/archive/dynamic_programming_rerooting.pdf
//https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#使用例


#include <iostream>
#include <vector>
#include <functional>
#include <stack>
using namespace std;
const long long INF = 1LL << 61;

template<class T> class reRooting{
    public:
    //ノード数
    int nodeCount;
    
    // 隣接している点の配列
    vector<vector<int>> Adjacents;
    // 隣接点にとって自分が何番目の隣接点なのか, to jが何番目なのか
    // adjacents[adjacents[i][j]][indexForAdjacents[i][j]] == i である
    vector<vector<int>> IndexForAdjacent;

    // Res[i] := iの子部分木の値
    vector<T> Res;
    //DP[i][j] := i, j := node id (jがiにとって何番目なのか)を親とし、adjacents[i][j]を根とした部分木の値  
    vector<vector<T>> DP;

    //単位元
    T Identity;
    // T merge(T left, T right){}で定義される部分期のマージ関数
    function<T(T, T)> Operate;
    //T addNode(T value, int nodeID) {} で定義される頂点の追加
    function<T(T, int)> OperateNode;


    public:
    reRooting(int _nodeCount, vector<vector<int>>& edges, T _identity, 
                function<T(T, T)> _operate, function<T(T, int)> _operateNode)
                :nodeCount(_nodeCount), Identity(_identity), Operate(_operate), OperateNode(_operateNode)    
    {
        vector<vector<int>> adjacents(nodeCount);
        vector<vector<int>> indexForAdjacent(nodeCount);

        //辺を見て配列に追加していく
        for(int i=0; i< edges.size(); ++i){
            auto& edge = edges[i];
            indexForAdjacent[edge[0]].push_back(adjacents[edge[1]].size());
            indexForAdjacent[edge[1]].push_back(adjacents[edge[0]].size());
            adjacents[edge[0]].push_back(edge[1]);
            adjacents[edge[1]].push_back(edge[0]);
        }

        Adjacents.resize(nodeCount);
        IndexForAdjacent.resize(nodeCount);

        for(int i=0; i<nodeCount; ++i){
            Adjacents[i] = adjacents[i];
            IndexForAdjacent[i] = indexForAdjacent[i];
        }
        DP.resize(Adjacents.size());
        for (int i = 0; i < Adjacents.size(); i++)
            DP[i].resize(Adjacents[i].size());

        Res.resize(Adjacents.size());

        if(nodeCount > 1){
            Initialize();
        }else if(nodeCount == 1){
            Res[0] = OperateNode(Identity, 0);
        }
    }

    T Query(int node) {return Res[node]; }

    private:
    void Initialize(){
        //parents[i] := 一時的な根付き木として考えた時の、ノードiについての親
        vector<int> parents(nodeCount);
        //order := DFSでの行きがけ順
        vector<int> order(nodeCount);

        //まず、一つの頂点について求めることを考えます。
        #pragma region InitOrderedTree
            int index = 0;
            stack<int> stack;
            //0を根とする
            stack.push(0);
            parents[0] = -1;
            //行きがけ順を記録する
            while(stack.size() > 0 ){
                auto node = stack.top();
                stack.pop();

                order[index++] = node;
                for(int i=0; i < Adjacents[node].size(); ++i){
                    auto adjacent = Adjacents[node][i];
                    if(adjacent == parents[node]) continue;
                    stack.push(adjacent);
                    parents[adjacent] = node;
                }
            }
        #pragma endregion

        //その次に、その訪問順を利用して部分木の値を求めます。
        //この操作で根付き木の根の方向(=親方向)以外の部分木の値が求まっているような状態になります。
        #pragma region fromLeaf
        for(int i=order.size()-1; i>= 1; --i){
            //現在の見ている頂点と、その親
            auto node = order[i];
            auto parent = parents[node];
            //結果
            T accum = Identity;
            int parentIndex = -1;
            //隣接する点を調べる
            for(int j=0; j< Adjacents[node].size(); ++j){
                //もし隣接する点が親だったら、親のindexの記録だけする
                if(Adjacents[node][j] == parent){
                    parentIndex = j;
                    continue;
                }
                //隣接する点方向の子部分木の結果を加える
                accum = Operate(accum, DP[node][j]);
            }
            //頂点を部分木のマ追加した後、親が持っている配列に結果を格納する
            //(親にとって自分が何番目の隣接頂点なのかを調べて格納)
            DP[parent][IndexForAdjacent[node][parentIndex]] = OperateNode(accum, node);
        }
        #pragma endregion


        //全ての頂点は根の方向からの部分木の値が求まれば頂点の値が求まるという状態になっている。
        //子部分木全てが揃った場合、両方向から累積を取る等で自分が根となる全ての部分木の値を求めることができます。
        #pragma region toLeaf
        //行きがけ順で頂点の値を確定させていく
        for(int i=0; i < order.size(); ++i){
            //値を確定させるnode
            auto node = order[i];
            
            //後ろからの累積和を格納する配列
            vector<T> accumsFromTail(Adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = Identity;
            for(int j = accumsFromTail.size() - 1; j >= 1; --j){
                accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            }

            //前からの累積和を持つ変数
            T accum = Identity;
            for(int j=0; j < accumsFromTail.size(); ++j){
                //adjacents[node][j]が親、nodeが子の部分木について計算する
                //累積をマージして子部分木の値をマージし終えた後、頂点を追加する
                T result = OperateNode(Operate(accum, accumsFromTail[j]), node);
                //その値を、親が持っている配列に結果を格納する(親にとって自分が何番目の隣接頂点なのかを調べて格納)
                DP[Adjacents[node][j]][IndexForAdjacent[node][j]] = result;

                //累積を更新
                accum = Operate(accum, DP[node][j]);
            }
            //最後まで累積しきったものはnodeの子部分木を全てマージしたものになっているので、それに頂点を追加するとnodeの値となる
            Res[node] = OperateNode(accum, node);
        }
        #pragma endregion
    }
};



//  ・問題
//  それぞれ1からNまでの番号が付いたN個の頂点からなる木が与えられる.各頂点について，
// その頂点から最も遠い頂点まで􏰀距離 を求めよ.
//  ・制約
//  1≦N≦100,000

//例
// input 
// 6
// 1 2
// 1 3
// 3 4
// 3 5
// 5 6

// output
// 7
// 6
// 8
// 7
// 7
// 6

int main(){
    int N;
    cin >> N;
    vector<vector<int>> edges;
    for(int i=0; i<N-1; ++i){
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        edges.push_back({from, to});
    }

    reRooting<int> rR(N, edges, 0, 
                [](long long a, long long b) { return (a+b);},[](long long value, int id) { return value+1; });
    
    long long ans = 0;
    for(int i=0; i<rR.Res.size(); ++i){
        ans += rR.Res[i];
//        cout << 2*(N-1) - (rR.Res[i] - 1) << endl;
    }

    cout << ans << endl;
}

// //別解by ケンチョン

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// using Graph = vector<vector<int>>;
// int N;
// Graph G;

// vector<vector<long long>> dp;

// long long rec(int v, int p = -1){
//     int s = G[v].size();
//     long long res = 0;

//     dp[v].assign(s, -1);
//     for(int i=0; i< s; ++i){
//         int to = G[v][i];
//         if(to == p) continue;
//         dp[v][i] = rec(to, v);
//         chmax(res, dp[v][i] + 1);
//     }
//     return res;
// }

// void rerec(int v, long long pval = 0, int p = -1){
//     int s = G[v].size();
//     for(int i=0; i< s; ++i){
//         int to = G[v][i];
//         if(to == p){
//             dp[v][i] = pval;
//             continue;
//         }
//     }

//     vector<long long> left(s+1, -1), right(s+1, -1);
//     for(int i=0; i<s; ++i){
//         left[i+1] = max(left[i], dp[v][i]);
//         right[i+1] = max(right[i], dp[v][s-i-1]);
//     }

//     for(int i=0; i < s; ++i){
//         int to = G[v][i];
//         if(to == p) continue;
//         rerec(to, max(left[i], right[s-i-1])+1, v);
//     }
// }

// int main(){
//     cin >> N;
//     G.assign(N, vector<int>());
//     for(int i=0; i<N-1; ++i){
//         int u, v; cin >> u >> v; --u, --v;
//         G[u].push_back(v);
//         G[v].push_back(u);
//     }

//     dp.assign(N, vector<long long>());
//     rec(0);
//     rerec(0);
//     for(int v=0; v<N; ++v){
//         long long res = 0;
//         for(int i=0; i < G[v].size(); ++i){
//             chmax(res, dp[v][i] + 1);
//         }
//         cout << (N-1)*2 - res << endl;
//     }
// }
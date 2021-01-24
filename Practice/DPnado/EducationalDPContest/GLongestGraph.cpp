// 解法2: BFS dp トポロジカルソート
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int> > G; // graph
vector<int> deg; //各頂点の入る次数（矢印をもらう側）

//int dp[100100];
int dp[30];

int main(){
    // 入力受け取り
    cin >> N >> M;
    G.assign(N, vector<int>());
    deg.assign(N, 0);
    for(int i=0; i<M; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
        deg[y]++;
    }

    //sourceをキューに入れる
    queue<int> que;
    for(int v=0; v<N; ++v) if(deg[v] ==0) que.push(v);

    //BFS
    while( !que.empty()){
        int v = que.front(); que.pop();
        for(auto nv: G[v]){
            deg[nv] --; // エッジ(v, nv) を破壊
            if(deg[nv] ==0){
                que.push(nv); //それによって入寺数が0にあったならキューにいれる
                dp[nv] = max(dp[nv], dp[v] +1);
            }
        }
    }

    //ans
    int res = 0;
    for(int v=0; v<N; ++v){
        res = max(res, dp[v]);
    }
    cout << res << endl;
}



// //解法1：DSFトポロジカルソート（メモ再帰）
// // dp[v] := ノード v を始点としたときの、G の有効パスの長さの最大値

// #include <iostream> 
// #include <vector>

// using namespace std;

// const long long INF = 1LL<<60;

// int N, M; // input
// vector<vector<int> > G; //graph

// // メモ化再帰
// int dp[100100];

// int rec( int v ){
//     if(dp[v] != -1) return dp[v]; // if it's updated, use the value

//     int res = 0;
//     for(auto nv : G[v]){
//         res = max(res, rec(nv) + 1);
//     }

//     return dp[v] = res; // memo and return
// }

// int main(){
//     cin >> N >> M;
//     G.assign(N, vector<int>());

//     for(int i=0; i<M; ++i){
//         int x, y;
//         cin >> x >> y;
//         --x, --y;
//         G[x].push_back(y);
//     }

//     //init(not visted)
//     for(int v=0; v<N; ++v) dp[v] = -1;

//     //memosaiki
//     int res = 0;
//     for(int v=0; v<N; ++v){
//         res = max(res, rec(v));
//     }

//     cout << res << endl;
// }

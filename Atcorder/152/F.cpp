#include <bits/stdc++.h>
#include <atcoder/all>
#include <chrono> 


using namespace std;
using namespace std::chrono; 
using namespace atcoder;



struct Edge {
    int id, to;
    Edge(int to, int id): id(id), to(to){}
};

bool dfs(int from, int dest, int parent, vector<vector<Edge>> &graph, vector<int> &visited){
    if(from == dest) return true;
    for(auto e : graph[from]){
        if(e.to == parent) continue;
        if( dfs(e.to, dest, from, graph, visited) ){
            visited.push_back(e.id);
            return true;
        }
    }
    return false;
}


int main(){
    int N; cin >> N;
    vector<vector<Edge>> graph( N, vector<Edge>());

    for(int i=0; i<N-1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }

    int M; cin >> M;
    //各条件がどの辺に対応するのかをbitで管理
    vector<long long> eset(M);
    for(int i=0; i<M; ++i){
        //どの辺を該当条件で訪れたのか記録
        vector<int> visited;
        int u, v; cin >> u >> v; u--; v--;
        dfs(u, v, -1, graph, visited);
        //条件の辺を2進数で管理
        for(int id: visited){
            eset[i] |= (1LL<<id);
        }
    }

    long long ans = 0;
    //2^mを全通り包除原理で計算する
    for(long long i=0; i<(1LL<<M); ++i){

        //該当条件のbitの立ってる部分を取り出す
        //bitは各条件に当てはまる
        long long mask = 0;
        for(int bit=0; bit<M; ++bit){
            if((i>>bit)&1){
                mask |= eset[bit];
            }
        }

        //何個あるのかを計算
        int edge_num = __builtin_popcountll(mask);
        //条件数が奇数このときは引く。偶数個は足す
        if(__builtin_popcountll(i)&1)
            ans -= pow(2, N-1-edge_num);
        else
            ans += pow(2, N-1-edge_num);
    }

    cout << ans << endl;
}
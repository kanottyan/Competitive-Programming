#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N, M; cin >> N >> M;

    vector<long long> H(N);

    //when visited i, what is the minimum dist.
    vector<long long> dist(N, -__LONG_LONG_MAX__);

    for(int i=0; i<N; ++i) cin >> H[i];
    vector<vector<pair<long long, long long>>> g(N);

    for(int i=0; i<M; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        if(H[u] <= H[v]){
            g[u].push_back({-2*(H[v]-H[u]), v});
            g[v].push_back({H[v]-H[u], u});
        }else{
            g[u].push_back({ H[u]-H[v], v});
            g[v].push_back({ -2*(H[u]-H[v]), u});
        }
    }

    //node, cur_dist
    priority_queue<pair<long long, long long>> que;
    que.push({0, 0});

    while( !que.empty() ){
        long long d = que.top().first;
        long long cur = que.top().second;
        que.pop();

        if( d <= dist[cur] ) continue;
        dist[cur] = d;
        for(auto d_idx : g[cur]){
            long long n_d = d_idx.first;
            long long n_i = d_idx.second;
            
            if( d + n_d < dist[n_i] ) continue;
            que.push({d+n_d, n_i});
        }
    }

    long long ans = 0;
    for(int i=0; i<N; ++i){
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;

    return 0;
}
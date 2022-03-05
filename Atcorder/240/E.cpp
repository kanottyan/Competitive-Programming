#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int leaves = 0;
vector<vector<int>> g;
vector<pair<int, int>> res;

void rec(int cur, int par){
    if(g[cur].size() == 1 && g[cur][0] == par ){
        leaves++;
        res[cur] = {leaves, leaves};
    }

    for(int n : g[cur]){
        if(n == par) continue;
        rec(n, cur);
        //merge
        res[cur].first = min(res[cur].first, res[n].first);
        res[cur].second = max( res[cur].second, res[n].second);
    }
}

int main(){
    int N; cin >> N;
    g.resize(N);
    res.resize(N);

    for(int i=0; i<N; ++i){
        res[i].first = INT_MAX;
        res[i].second = 0;
    }

    for(int i=0; i<N-1; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //count leaves
    rec(0, -1);

    for(int i=0; i<N; ++i){
        cout << res[i].first << " " << res[i].second << endl;
    }



    return 0;
}
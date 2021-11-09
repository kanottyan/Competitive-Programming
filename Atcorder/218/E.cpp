#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> edges(M);

    dsu d(N);

    long long tot = 0;

    for(int i=0; i<M; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges[i].push_back(c);
        edges[i].push_back(a);
        edges[i].push_back(b);
        tot += c;
    }

    sort(edges.begin(), edges.end());

    long long mst = 0;
    for(int i=0; i<M; ++i){
        if(edges[i][0] > 0 && d.same(edges[i][1], edges[i][2])) continue;
        d.merge(edges[i][1], edges[i][2]);
        mst += edges[i][0];
    }

    long long ans = tot - mst;

    cout << ans << endl;

}
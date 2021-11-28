#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<set<int>> can_maeger_candidate(N);
    dsu d(N);

    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> ans;
    ans.push_back(0);
    int num = 0;
    for(int i=N-1; i>=1; --i){
        num++;
        for(int node : can_maeger_candidate[i]){
            if(d.leader(node) == d.leader(i)) continue;
            d.merge(i, node);
            num--;
        }

        for(int node: g[i]){
            can_maeger_candidate[node].insert(i);
        }
        ans.push_back(num);
    }

    reverse(ans.begin(), ans.end());
    
    for(int i=0; i<N; ++i) cout << ans[i] << endl;

    return 0;
}
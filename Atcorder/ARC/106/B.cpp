#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M; cin >> N >> M;

    dsu uf(N);

    vector<long long> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    vector<long long> b(N);
    for(int i=0; i<N; ++i) cin >> b[i];

    set<int> done_group;
    for(int i=0; i<M; ++i){
        int c, d; cin >> c >> d;
        c--; d--;
        uf.merge(c, d);
    }

    string ans = "Yes";
    for(auto group_noods : uf.groups()){
        long long suma = 0;
        long long sumb = 0;
        for(auto node_id : group_noods){
            suma += a[node_id];
            sumb += b[node_id];
        }

        if(suma != sumb) ans = "No";
    }

    cout << ans << endl;
}
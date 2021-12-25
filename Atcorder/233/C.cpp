#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    map<long long, long long> m;

    long long N, X; cin >> N >> X;
    vector<vector<long long>> L(N);

    for(long long i=0; i<N; ++i){
        long long l; cin >> l;
        for(long long j=0; j<l; ++j){
            long long a; cin >> a;
            L[i].push_back(a);
        }
    }

    for(long long i=0; i<L[0].size(); ++i){
        m[L[0][i]]++;
    }

    for(long long i=1; i<N; ++i){
        map<long long, long long> nm;
        for(long long j=0; j<L[i].size(); ++j){
            for(auto p : m){
                if( p.first > X/L[i][j] ) continue;
                // probably better overlow handling
                long long res = p.first * L[i][j];
                
                //if overflow then ignore
                //if (res == 0 || res/L[i][j] != p.first || res/p.first != L[i][j] ) continue;
                nm[res] += m[p.first];
            }            
        }
        swap(m, nm);
    }

    long long ans = 0;
    if(m.count(X) > 0) ans = m[X];

    cout << ans << endl;

    return 0;
}
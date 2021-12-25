#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main(){
    int n, d; cin >> n >> d;
    vector<mint> f(n+1), g(n+1);
    vector<mint> two(n+1);
    two[0] = 1;
    for(int i=0; i<n; ++i) two[i+1] = two[i]*2;

    for(int i=1; i<=n; ++i){
        int l = i-1, r = d-l;

        mint leaf = 0;
        if(0 <=r && r <= i-1){
            leaf = two[max(l-1, 0)]*two[max(r-1, 0)];
            if(l != r) leaf *= 2;
        }
        g[i] = g[i-1] + leaf;
    }

    for(int i=1; i <= n; ++i){
        f[i] = f[i-1]*2 +g[i];
    }

    cout << (f[n]*2).val() << endl;

    return 0;
}
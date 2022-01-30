#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    map<int, vector<int>> m;
    for(int i=0; i<N; ++i){
        m[A[i]].push_back(i+1);
    }

    while(Q--){
        int x, k; cin >> x >> k;
        int ans;
        if( m[x].size()< k ) ans = -1;
        else ans = m[x][k-1];

        cout << ans << endl;
    }


    return 0;
}
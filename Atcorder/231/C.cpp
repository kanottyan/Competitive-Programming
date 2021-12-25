#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    long long N, Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    while(Q--){
        long long x; cin >> x;
        auto iter = lower_bound(A.begin(), A.end(), x);
        long long ans = distance(iter, A.end());
        cout << ans << endl;
    }
        

    return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// long long solve(long long M, long long A, long long B, long long N){
//     long long ans = N*(2*B+(N-1)*A)/2;
//     ans /= M;
//     return ans;
// }

int main(){
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        long long N, M, A, B;
        cin >> N >> M >> A >> B;
        cout << floor_sum(N, M, A, B) << endl;
    }


}
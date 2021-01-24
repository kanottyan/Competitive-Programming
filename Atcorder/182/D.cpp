#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N; cin >> N;
    vector<long long> a(N);

    for(int i=0; i<N; ++i) cin >> a[i];

    vector<long long> cumsum(N+1);
    cumsum[0] = 0;
    for(int i=0; i<N; ++i){
        cumsum[i+1] = cumsum[i] + a[i];
    }

    long long ans = 0;
    long long b_max = 0;
    long long s = 0;
    for(int i=0; i<=N; ++i){
        b_max = max(b_max, cumsum[i]);
        ans = max(ans, s + b_max);
        s += cumsum[i];
    }

    cout << ans << endl;
}

// int main(){

//     long long N; cin >> N;
//     vector<long long> A(N);
//     for(long long i=0; i<N; ++i) cin >> A[i];

//     vector<long long> cumsum(N+1, 0);
//     vector<long long> cumsum2(N+2, 0);
//     cumsum[0] = 0;
//     for(int i=0; i<N; ++i){
//         cumsum[i+1] += (cumsum[i]+A[i]);
//     }

//     long long max_cumsum2_idx = -1;
//     long long max_cumsum2 = 0;

//     for(long long i=0; i<N+1; ++i){
//         cumsum2[i+1] += (cumsum2[i]+cumsum[i]);
//     }


//     for(long long i=0; i<N+2; ++i){
//         if( max_cumsum2 <= cumsum2[i]){
//             max_cumsum2_idx = i;
//             max_cumsum2 = cumsum2[i];
//         }
//     }
//     if(max_cumsum2_idx == N+1) max_cumsum2_idx -= 1;

//     long long max_cumsum_idx = max_cumsum2_idx - 1;

//     long long ans = 0;
//     long long max_ans = 0;
//     for(int i=0; i<=max_cumsum_idx; ++i){
//         ans += cumsum[i];
//     }


//     for(long long j=0; j<=max_cumsum_idx; ++j){
//         ans += A[j];
//         max_ans = max(max_ans, ans);
//     }

//     cout << max_ans << endl;

//     // vector<long long> table(N+1);
//     // for(int i=0; i<N; ++i){
//     //     table[i] += A[i];
//     //     table[N] -= A[i];
//     // }

//     // for(int i=0; i<N; ++i){
//     //     if(0 <i) table[i] += table[i-1];
//     // }


//     return 0;
// }
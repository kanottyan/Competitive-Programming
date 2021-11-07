#include <bits/stdc++.h>
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using mint=modint998244353;


// in ith element, suppose Ci = j, then how many pathes we have as choice
mint dp[3010][3010];

int main(){
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N; ++i) cin >> B[i];

    dp[0][0] = 1;

    vector<mint> cumsum(3010);
    cumsum[0] = 0;

    for(int i=0; i<N; ++i){
        for(int j=0; j<=3000; ++j){
            cumsum[j+1] = (cumsum[j] + dp[i][j]);
        }

        for(int j=0; j<=3000; ++j){
            if( A[i] <=j && j<= B[i]){
                dp[i+1][j] = cumsum[j+1];
            }else{
                dp[i+1][j] = 0;
            }
        }
    }

    mint ans = 0;
    for(int i=0; i<=3000; ++i){
        ans += dp[N][i];
    }    
    cout << ans.val() << endl;
}

// #include <bits/stdc++.h>
// #include <atcoder/all>
// #include <bits/stdc++.h>

// using namespace std;
// using namespace atcoder;

// using mint=modint998244353;


// // in ith element, suppose Ci = j, then how many pathes we have as choice
// mint dp[3010][3010];

// int main(){
//     int N; cin >> N;
//     vector<int> A(N);
//     vector<int> B(N);

//     for(int i=0; i<N; ++i) cin >> A[i];
//     for(int i=0; i<N; ++i) cin >> B[i];

//     dp[0][0] = 1;

//     for(int i=0; i<=N; ++i){
//         for(int j=0; j<=3000; ++j){
//             dp[i][j+1] += dp[i][j];
//             if( A[i] <=j && j<= B[i]){
//                 dp[i+1][j] += dp[i][j];
//             }
//         }
//     }

//     mint ans = 0;

//     cout << dp[N][3000].val() << endl;
// }
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

// dp[i] は切る場所がそこの場合、何通りで切れるのか。
// dp[0]は切らない（全体）をしめす。

int main(){
    int S; cin >> S;

    vector<long long> dp(2010, 0);
    dp[0] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    
    for(int i=6; i<=S; ++i){
        for(int j=0; j<=i-3; ++j){
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[S] << endl;
}

// int main(){
//     int S;
//     cin >> S;
//     vector<long long> dp(2010, 0);
//     dp[0] = 1;

//     for(int i=0; i<2010; ++i){
//         for(int j=0; j<=i-3; ++j){
//             dp[i] += dp[j];
//             dp[i] %= MOD;
//         }
//     }

//     cout << dp[S] << endl;

// }
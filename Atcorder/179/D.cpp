#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

//わたすdp
int main(){
    int N,K;
    cin >> N >> K;
    N += 10;
    vector<pair<int, int>> range(K);
    for(int i=0; i<K; ++i){
        int L, R;
        cin >> L >> R;
        range[i] = {L, R};
    }

    vector<int> dp(N);
    dp[0] = 1;
    dp[1] = -1; //+ MOD;
    for(int i=0; i<=N; ++i){
        if(i  > 0){
            dp[i] += dp[i-1];
            //dp[i] %= MOD;
        } 
        for(int j=0; j<K; ++j){
            int l = range[j].first;
            int r = range[j].second;

            if(i + l <N){
                dp[i + l] += dp[i];
                // dp[i + l] %= MOD;
            }

            if(i + r +1 <N){
                dp[i + r +1] -= dp[i];
                // if(dp[i + r + 1] < 0) dp[i + r + 1] += MOD;
                // dp[i+r+1] %= MOD;
            } 
        }
    }

    cout << dp[N-1] << endl;
}

// //もらうdp
// int main(){
//     int N,K;
//     cin >> N >> K;
    
//     vector<pair<int, int>> range(K);
//     for(int i=0; i<K; ++i){
//         int L, R;
//         cin >> L >> R;
//         L;
//         R;
//         range[i] = {L, R};
//     }

//     vector<int> dp(N+1);
//     vector<int> dp_sum(N+1);
//     dp[1] = 1;
//     dp_sum[1] = 1;
//     for(int i=2; i<=N; ++i){
//         for(int j=0; j<K; ++j){
//             int l = range[j].first;
//             int r = range[j].second;
//             int li = i - r;
//             int ri = i - l;
//             li = max(1, li);
//             if(ri < 0) continue;

//             int tmp = dp_sum[ri] - dp_sum[li -1];
//             if(tmp < 0) tmp += MOD;
//             dp[i] += tmp;
//             dp[i] %= MOD;
//         }
//         dp_sum[i] = dp_sum[i-1] + dp[i];
//         dp_sum[i] %= MOD;
//     }

//     cout << dp[N] << endl;

// }

// int main(){
//     int N, K;
//     cin >> N >> K;

//     set<long long> s;
//     vector<long long> l(K);
//     vector<long long> r(K);

//     for(long long i=0; i<K; ++i){
//         cin >> l[i] >> r[i];
//     }

//     vector<long long> dp(N+10);
//     vector<long long> dp_sum(N+10);

//     dp[1] = 1;
//     dp_sum[1] = 1;

//     for(int i=2; i < N+10; ++i){
//         for(int j=0; j<K; ++j){
//             int li = i - r[j];
//             int ri = i - l[j];
//             if(ri < 0) continue;
//             li = max(1, li);
//             long long tmp = dp_sum[ri] - dp_sum[li-1];
//             if(tmp < 0) tmp += MOD;
//             dp[i] += tmp;
//             dp[i] %= MOD;
//         }
//         dp_sum[i] += dp_sum[i-1] + dp[i];
//         dp_sum[i] %= MOD;
//     }

//     cout << dp[N] << endl;
// }
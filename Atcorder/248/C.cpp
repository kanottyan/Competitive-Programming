#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// dp[N][M] --> i'm N times, and how many cases available to be sum of M
int dp[51][2501];

int main(){
    int N, M, K; cin >> N >> M >> K;

    for(int i=1; i<=M; ++i){
        if( i <= K){
            dp[0][i] = 1;
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=1; j<2501; ++j){
            for(int k=1; k<=M; ++k){
                if(j+k <= K){
                    dp[i+1][j+k] += dp[i][j];
                    dp[i+1][j+k] %= 998244353;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=K; ++i){
        ans += dp[N-1][i];
        ans %= 998244353;
    }

    cout << ans << endl;


}
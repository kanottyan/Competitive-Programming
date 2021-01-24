#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main(){
    long long h, n;
    cin >> h >> n;
    vector<long long> dp(h+1, INF);

    dp[0]= 0;
    for(long long i=0; i<n; ++i){
        long long a, b; cin >> a >> b;
        for(long long j=0; j<h; ++j){
            long long nj = min(j+a, h);
            dp[nj] = min(dp[nj], dp[j]+b);
        }
    }

    cout << dp[h] << endl;
}

// long long dp[1005][10005];

// int main(){
//     int H, N;
//     cin >> H >> N;

//     vector<long long> A(N);
//     vector<long long> B(N);
//     for(int i=0; i<N; ++i){
//         cin >> A[i];
//         cin >> B[i];
//     }

//     //init
//     for(int i=0; i<N; ++i){
//         for(int j=0; j<H; ++j){
//             dp[i][j] = INF;
//         }
//     }

//     //first line
//     for(int j=0; j<H; ++j){
//         int life = j +1;
//         int cnt = (life+A[0]-1)/A[0];
//         dp[0][j] = cnt * B[0];
//     }

//     //from second line
//     for(int i=1; i<N; ++i){
//         for(int j=0; j<H; ++j){
//             dp[i][j] = min(dp[i][j], dp[i-1][j]);
//         }

//         for(int j=0; j<H; ++j){
//             int life = j+1;
//             if(life <= A[i]){
//                 int cnt = (life+A[i]-1)/A[i];
//                 dp[i][j] = min(cnt * B[i], dp[i-1][j]);
//             }

//             if(life + A[i] <= H){
//                 dp[i][j + A[i]] = min( dp[i][j + A[i]], dp[i][j] + B[i] );
//             }
//         }
//     }

//     cout << dp[N-1][H-1] << endl;
// }
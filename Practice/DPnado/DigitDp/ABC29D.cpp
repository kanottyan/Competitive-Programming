// #include <bits/stdc++.h>
// #define LOOP(n) for (int _i = 0; _i < (n); _i++)
// #define REP(i, n) for (int i = 0; i < (n); ++i)
// #define RREP(i, n) for (int i = n; i >= 0; --i)
// #define FOR(i, r, n) for (int i = (r); i < (n); ++i)
// #define ALL(obj) begin(obj), end(obj)
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;
 
// const int MOD = 1e9 + 7;
 
// string N;
// ll dp[11][2][11];
 
// int main() {
//     cin >> N;
//     int n = N.size();
 
//     dp[0][0][0] = 1;
 
//     REP(i, n) {
//         REP(j, 5) {
//             // i桁目まででNより小さいならi+1桁目は何でも良い
//             dp[i + 1][1][j] += dp[i][1][j] * 9;  // i+1桁目が1以外
//             dp[i + 1][1][j + 1] += dp[i][1][j];  // i+1桁目が1
 
//             int ni = (N[i] - '0');
 
//             // i桁目までNと同じで、i+1桁目はNより小さい数の時
//             if (ni > 1) {
//                 dp[i + 1][1][j] += dp[i][0][j] * (ni - 1);  // i+1桁目が0~ni-1のうちの1以外
//                 dp[i + 1][1][j + 1] += dp[i][0][j];         // i+1桁目が1
//             } else if (ni == 1) {
//                 dp[i + 1][1][j] += dp[i][0][j];  // i+1桁目が0
//             }
 
//             //  i桁目までNと同じで、i+1桁目もNと同じ数の時
//             if (ni == 1) {
//                 dp[i + 1][0][j + 1] = dp[i][0][j];  // i+1桁目が1
//             } else {
//                 dp[i + 1][0][j] = dp[i][0][j];  // i+1桁目が1以外
//             }
//         }
//     }
//     ll ans = 0;
//     REP(j, 10) { ans += (dp[n][0][j] + dp[n][1][j]) * j; }
 
//     cout << ans << endl;
 
//     return 0;
// }
 

// //https://atcoder.jp/contests/abc029/tasks/abc029_d
// //https://algo-logic.info/digit-dp/

#include <iostream>
#include <vector>
#include <string>
#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

const int MOD = 1e9+7;
long long dp[11][2][11];

//dp[ i ][smaller][ j ] :=
// i 桁目までを決めた時、 1 が j 回出現する数がいくつあるか。
//ただし smaller が true ならNより小さい場合を考え、
// smallerが false ならNと同じ場合を考える。

int main(){
    string N; cin >> N;
    int n = N.size();
    //init,　最初の桁0はNと同じ桁で1を含まない.
    dp[0][0][0] = 1;

    //桁数 i
    for(int i=0; i<n; ++i){
        //条件　j
        for(int j=0; j<10; ++j){
            //smaller flag の場合分け

            //1. i桁目まででNより小さいならi+1桁は何でも良い
            //fill in the dp below is the example
            // dp[i+1][1][ (j+k)%D ] += dp[i][1][j];
            // dp[i+1][1][(j+k) % D] %= MOD;
            dp[i+1][1][j] += dp[i][1][j] *9; // i+1桁が0,2-9;
            dp[i+1][1][j+1] += dp[i][1][j];  // i+1桁が1



            //2. i桁目までNと同じでi+1はNより小さい
            int ni = (N[i] - '0');
            // for(int k=0; k<ni; ++k){
                //fill in the dp below is the example
                // dp[i+1][1][ (j+k) % D ] += dp[i][0][j];
                // dp[i+1][1][ (j+k) % D ] %= MOD;
            // }
            if(ni > 1){
                dp[i+1][1][j] += dp[i][0][j] * (ni - 1);    // i+1桁目が0~ni-1のうちの1以外
                dp[i + 1][1][j + 1] += dp[i][0][j];         // i+1桁目が1
            }else if(ni == 1){
                dp[i+1][1][j] +=  dp[i][0][j]; // i+1が0
            }

            //3. i桁目めでNと同じで i+1も同じ数
            // fill in the dp below is the example
            // dp[i+1][0][ (j+ni) % D ] = dp[i][0][j];
            if(ni == 1){
                //i+1が1
                dp[i+1][0][j+1] = dp[i][0][j];
            }else{ 
                dp[i+1][0][j] = dp[i][0][j];
            }
        }
    }

    // anser would be something like below
    // cout << dp[n][1][0] + dp[n][0][0] - 1 << endl; 
    long long ans = 0;
    for(int j=0; j<10; ++j){
        ans += (dp[n][0][j] + dp[n][1][j]) * j;
    }

    cout << ans << endl;
}
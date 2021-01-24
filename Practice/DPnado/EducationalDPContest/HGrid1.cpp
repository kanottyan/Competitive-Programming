// #include <iostream>
// #include <vector>
// #include <stack>
// #include <cstring>

// using namespace std;
// const int MOD = 1000000007;

// int dp[1010][1010];
// char table[1010][1010];

// int main(){
//     int H, W;
//     cin >> H >> W;

//     memset(dp, 0, sizeof(dp));

//     for(int h=0; h<=H; ++h){
//         table[h][0] = '.';
//     }
//     for(int w=0; w<=W; ++w){
//         table[0][w] = '.';
//     }

//     for(int h=1; h<=H; ++h){
//         for(int w=1; w<=W; ++w){
//             cin >> table[h][w];
//         }
//     }
//     dp[1][1]=1;

//     for(int h=1; h<=H; ++h){
//         for(int w=1; w<=W; ++w){
//             if( table[h-1][w] != '#' && table[h][w-1] != '#' ){
//                 dp[h][w] += dp[h-1][w] + dp[h][w-1];
//                 dp[h][w] %= MOD;
//             }else if( table[h-1][w] == '#' && table[h][w-1] != '#' ){
//                 dp[h][w] += dp[h][w-1];
//                 dp[h][w] %= MOD;
//             }else if( table[h-1][w] != '#' && table[h][w-1] == '#' ){
//                 dp[h][w] += dp[h-1][w];
//                 dp[h][w] %= MOD;
//             }else{
//                 dp[h][w] = 0;
//                 dp[h][w] %= MOD;
//             }
//         }
//     }

//     cout << dp[H][W] << endl;

// }

// good kaitou
#include <iostream>
#include <vector>
#include <string>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// MOD
const int MOD = 1000000007;

// 入力
int H, W;
vector<string> a;

// DP テーブル
int dp[1100][1100] = {0};

// add
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    cin >> H >> W;
    a.resize(H);
    for (int i = 0; i < H; ++i) cin >> a[i];

    // DP 初期化: すでに配列全体が 0 に初期化されているので OK

    // DP 初期条件
    dp[0][0] = 1;

    // DP ループ
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i+1 < H && a[i+1][j] == '.') add(dp[i+1][j], dp[i][j]);
            if (j+1 < W && a[i][j+1] == '.') add(dp[i][j+1], dp[i][j]);
        }
    }
    cout << dp[H-1][W-1] << endl;
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

void chmin(int& x, int y){x = min(x,y);}
const int INF = 100000000; // 十分大きな値

//1. for文で解く方法
int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for(int i=0; i<n; ++i) cin >> x[i] >> y[i] >> z[i];

    int n2 = 1 << n;
    //dp[S][v] := いままで　訪れた頂点集合がS。今いる頂点がVのときの最小コスト
    vector<vector<int>> dp(n2, vector<int>(n, INF));
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int now = abs(x[i] - x[j]);
            now += abs(y[i] - y[j]);
            now += max(0, z[j] - z[i]);
            dist[i][j] = now;
        }
    }

    //初期値: 0から行くときの距離
    for(int i=0; i<n; ++i){
        if(i == 0) continue;
        dp[1<<i][i] = dist[0][i];
    }
    for(int i=0; i<n2; ++i){
        for(int j=0; j<n; ++j){
            //そもそもその桁をビットがないとだめなので
            //iにjが入ってなかったらだめの意味
            if( ~i>>j&1 ) continue;
            //jからkに向かう
            for(int k=0; k<n; ++k){
                //kがiに含まれてたらだめ
                if(i>>k&1)continue;
                //　(i|1<<k)はiのk桁目に１を足す
                chmin(dp[i|1<<k][k], dp[i][j] + dist[j][k] );
            }
        }
    }
    cout << dp[n2-1][0] << endl;
}

// /* 入力 */
// 再帰で解く方法
// int N;
// int dist[21][21];

// /* メモ再帰 */
// int dp[(1<<21) + 1][21]; // dpテーブルは余裕をもったサイズにする
// int rec(int bit, int v)
// {
//     // すでに探索済みだったらリターン
//     if (dp[bit][v] != -1) return dp[bit][v];

//     // 初期値は点０からその点に行くまでの距離
//     if (bit == (1<<v)) {
//         return dp[bit][v] = dist[0][v];
//     }

//     // 答えを格納する変数
//     int res = INF;

//     // bit の v を除いたもの
//     int prev_bit = bit & ~(1<<v);

//     // v の手前のノードとして u を全探索
//     for (int u = 1; u < N; ++u) {
//         if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらそもそもそのケースはuからvに行けないのでだめ

//         // 再帰的に探索
//         if (res > rec(prev_bit, u) + dist[u][v]) {
//             res = rec(prev_bit, u) + dist[u][v];
//         }
//     }

//     return dp[bit][v] = res; // メモしながらリターン
// }

// int main()
// {
//     // 入力
//     cin >> N;
//     vector<int> X(N);
//     vector<int> Y(N);
//     vector<int> Z(N);

//     for(int i=0; i<N; ++i){
//         cin >> X[i] >> Y[i] >> Z[i];
//     }

//     for(int i=0; i<N; ++i){
//         for(int j=0; j<N; ++j){
//             int d = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0, Z[j] - Z[i]); 
//             dist[i][j] = d;
//         }
//     }

//     // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
//     for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

//     // 探索は最後0に戻る
//     int ans = rec((1<<N)-1, 0);

//     cout << ans << endl;
// }
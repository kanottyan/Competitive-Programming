#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 入力
int N;
vector<double> p;

// DP テーブル
//dp[i][j] := 最初の i 枚のコインを投げたときに、表が j 枚となる確率
//double dp[3100][3100];

double dp[30][30];


int main() {
    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; ++i) cin >> p[i];

    // 初期条件
    dp[0][0] = 1.0;

    // DP ループ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    // 答え
    double res = 0.0;
    for (int j = N/2 + 1; j <= N; ++j) res += dp[N][j];
    cout << fixed << setprecision(10) << res << endl;
}
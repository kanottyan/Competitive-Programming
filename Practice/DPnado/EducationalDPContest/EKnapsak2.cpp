//https://atcoder.jp/contests/dp/tasks/dp_e

#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL<<60;
const int MAX_N = 110;
const int MAX_V = 100100;
long long dp[MAX_N][MAX_V];

int main(){
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> w(N);
    vector<long long> v(N);

    for(int i=0; i<N; ++i){
        cin >> w[i];
        cin >> v[i];
    }

    // 初期化
    for (int i = 0; i < MAX_N; ++i) for (int j = 0; j < MAX_V; ++j) dp[i][j] = INF;
    // 初期条件
    dp[0][0] = 0;

    //j means sum_v
    for(int i=0; i<N; ++i){
        for(int j=0; j<MAX_V; ++j){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j - v[i] >=0){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j-v[i]]+w[i]);
            }else{
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }

    // 最適値の出力
    long long res = 0;
    for (int sum_v = 0; sum_v < MAX_V; ++sum_v) {
        if (dp[N][sum_v] <= M) res = sum_v;
    }
    cout << res << endl;
}
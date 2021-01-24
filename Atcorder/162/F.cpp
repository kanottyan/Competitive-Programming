#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

long long dp[200005][4];
//long long dp[100][4];

//dp[i][j] : i個目まで見てj個余分なｘ（バツ）を入れたときのMAX

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    //K: 何個余分のバツを入れれる？奇数は2で偶数は1
    int K = 1 + N%2;

    for(int i=0; i< N+1; ++i){
        for(int j=0; j<K+1; ++j){
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<K+1; ++j){
            //バツを一個挿入（今見てる数をスキップ）
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            //次の数を当てはめる,0からなので割り切れたらそれはカウント
            long long now = dp[i][j];
            if( (i+j)%2 == 0 ) now += a[i];
            dp[i+1][j] = max(dp[i+1][j], now);            
        }
    }

    long long ans = dp[N][K];
    cout << ans << endl;

}
//https://atcoder.jp/contests/dp/tasks/dp_d

#include <iostream>
#include <vector>

using namespace std;

long long dp[110][101000] = {0};

int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> w(N);
    vector<long long> v(N);

    for(long long i=0; i<N; ++i){
        cin >> w[i];
        cin >> v[i];
    }

    for(long long i=1; i<=N; ++i){
        for(long long j=1; j<=M; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
        }
    }

    cout << dp[N][M] << endl;
}
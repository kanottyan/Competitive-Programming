//https://atcoder.jp/contests/dp/tasks/dp_c

#include <iostream>
#include <cmath>

using namespace std;
int dp[110000][3];
int happy[110000][3];
// int dp[110][3];
// int happy[110][3];

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; ++i){
        for(int j=0; j<3; ++j){
            cin >> happy[i][j];
        }
    }
    
    //init
    for(int j=0; j<3; ++j) dp[0][j] = 0;
    
    // i:日数, j:どのタスクを選ぶか, k:前日何を行ったか　
    for(int i=1; i<=N; ++i){
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k){
                if(j!=k){
                    dp[i][k] = max(dp[i][k],dp[i-1][j] + happy[i-1][k]);
                }
            }
        }
    }
    int res;
    res = max(dp[N][0], dp[N][1]);
    res = max(res, dp[N][3]);

    cout << res << endl;
}
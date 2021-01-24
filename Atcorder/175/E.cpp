#include <bits/stdc++.h>
using namespace std;


long long dp[10][10][4];

int main(){
    int R, C, K; cin >> R >> C >> K;
    vector<vector<long long>> table(R, vector<long long>(C));

    for(int i=0; i<K; ++i){
            int r, c, v;
            cin >> r >> c >> v;
            r--; c--;
            table[r][c] = v;
    }

    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            for(int k=2; k>=0; --k){
                //そのマスを拾う
                dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] + table[i][j]);
            }
            for(int k=0; k<=3; ++k){
                //右に移動
                dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);

                //下に移動
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);
            }
        }
    }

    // //init
    // for(int i=0; i<R; ++i){
    //     for(int j=0; j<C; ++j){
    //         for(int k=0; k<3; ++k){
    //             //右に行く場合
    //             //今のますを使う場合
    //             dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + table[i][j]);
    //             // 今のますを使わない場合
    //             dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k+1]);

    //             //下に行く場合
    //             dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j+1][k+1]);
    //         }
    //     }
    // }

    long long ans = 0;
    for(int i=0; i<4; ++i){
        ans = max( ans, dp[R-1][C-1][i] );
    }

    cout << ans << endl;
}
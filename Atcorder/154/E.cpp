#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc029/tasks/abc029_d
//https://algo-logic.info/digit-dp/

#include <iostream>
#include <vector>

using namespace std;

//dp[ i ][smaller][ j ] := i 桁目までの各桁の数の0でないj個数。
//ただし smaller が true ならNより小さい場合を考え、
//smallerが false ならNと同じ場合を考える。

long long dp[1005][2][5];

int main(){
    string N; cin >> N;
    int keta = N.size();
    int K; cin >> K;

    dp[0][0][0] = 1;
    //桁数 i
    for(int i=0; i<keta; ++i){
        //条件 j　
        for(int j=0; j<=3; ++j){
            //smaller flag の場合分け

            //1. i桁目まででNより小さいならi+1桁は何でも良い
            // for(int k=0; k<10; ++k){
            //     //fill in the dp below is the example
            //     // dp[i+1][1][ (j+k)%D ] += dp[i][1][j];
            //     // dp[i+1][1][(j+k) % D] %= MOD;
            // }
            dp[i+1][1][j+1] += dp[i][1][j] *9; // i+1桁が1-9;
            dp[i+1][1][j] += dp[i][1][j];  // i+1桁が0

            int ni = (N[i] - '0');
            //2. i桁目までNと同じでi+1はNより小さい
            // for(int k=0; k<ni; ++k){
            //     //fill in the dp below is the example
            //     // dp[i+1][1][ (j+k) % D ] += dp[i][0][j];
            //     // dp[i+1][1][ (j+k) % D ] %= MOD;
            // }
            if(ni >= 1){
                dp[i+1][1][j+1] += dp[i][0][j] *(ni-1);    // j+1は（i+1桁目が1~ni-1）でできる
                dp[i+1][1][j] += dp[i][0][j];               // jも同様に一回加算できる（これは前の桁が0だった場合に対応）
            }

            //3. i桁目めでNと同じで i+1も同じ数
            // fill in the dp below is the example
            // dp[i+1][0][ (j+ni) % D ] = dp[i][0][j];
            if(ni == 0){
                //i+1が0
                dp[i+1][0][j] = dp[i][0][j];
            }else{ 
                dp[i+1][0][j+1] = dp[i][0][j];
            }

        }
    }

    cout << dp[keta][1][K] + dp[keta][0][K] << endl;

}
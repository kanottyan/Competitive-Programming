//https://atcoder.jp/contests/abc029/tasks/abc029_d
//https://algo-logic.info/digit-dp/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;
long long dp[10005][2][105];

int main(){

    dp[0][0][0] = 1;
    //桁数 i
    for(int i=0; i<(finn in here, would be the num of the digit); ++i){
        //条件 j　
       for(int j=0; j<(fill in here, depends on the condition); ++j){
            //smaller flag の場合分け

            //1. i桁目まででNより小さいならi+1桁は何でも良い
            for(int k=0; k<10; ++k){
                //fill in the dp below is the example
                // dp[i+1][1][ (j+k)%D ] += dp[i][1][j];
                // dp[i+1][1][(j+k) % D] %= MOD;
            }

            int ni = (N[i] - '0');
            //2. i桁目までNと同じでi+1はNより小さい
            for(int k=0; k<ni; ++k){
                //fill in the dp below is the example
                // dp[i+1][1][ (j+k) % D ] += dp[i][0][j];
                // dp[i+1][1][ (j+k) % D ] %= MOD;
            }

            //3. i桁目めでNと同じで i+1も同じ数
            // fill in the dp below is the example
            // dp[i+1][0][ (j+ni) % D ] = dp[i][0][j];
        }
    }

    // anser would be something like below
    // cout << dp[n][1][0] + dp[n][0][0] - 1 << endl; 
}
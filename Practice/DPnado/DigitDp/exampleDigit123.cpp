//https://atcoder.jp/contests/tdpc/tasks/tdpc_number
//https://algo-logic.info/digit-dp/
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

const int MOD = 1e9+7;

int D;
string N;
long long dp[10005][2][105];
//dp[ i ][smaller][ j ] := i 桁目までの各桁の数の和が mod Dで
// j となる数。
//ただし smaller が true ならNより小さい場合を考え、
//smallerが false ならNと同じ場合を考える。

int main(){
    cin >> D >> N;
    int n = N.size();
    dp[0][0][0] = 1;
    //桁数
    for(int i=0; i<n; ++i){
        //条件　jが0になるかどうか
        for(int j=0; j<D; ++j){
            //smaller flag の場合分け

            //1. i桁目まででNより小さいならi+1桁は何でも良い
            for(int k=0; k<10; ++k){
                dp[i+1][1][ (j+k)%D ] += dp[i][1][j];
                dp[i+1][1][(j+k) % D] %= MOD;
            }

            int ni = (N[i] - '0');
            //2. i桁目までNと同じでi+1はNより小さい
            for(int k=0; k<ni; ++k){
                dp[i+1][1][ (j+k) % D ] += dp[i][0][j];
                dp[i+1][1][ (j+k) % D ] %= MOD;
            }

            //3. i桁目めでNと同じで i+1も同じ数
            dp[i+1][0][ (j+ni) % D ] = dp[i][0][j];
        }
    }

    cout << dp[n][1][0] + dp[n][0][0] - 1 << endl; 
}
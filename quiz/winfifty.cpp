// you toss coins 100 times. first time is head and second time is tail
// Nth coins head probability is wining count/total try so far
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    //dp[i][j] denote In ith try, the probability get head j times
    double dp[101][101];
    for(int i=0; i<=100; ++i) for(int j=0; j<=100; ++j) dp[i][j] = 0;
    dp[2][1] = 1.0;


    for(long long i=3;i<= 100; ++i){
        for(long long j=1; j<=100; ++j){
            if(j > i-1) continue;
            //win 
            dp[i][j] += dp[i-1][j-1]*(j-1.0)/(i-1.0) ;
            //lose
            dp[i][j] += dp[i-1][j]*(1.0 -(j/(i-1.0)));        
        }
    }

    cout << dp[100][50] << endl;


}
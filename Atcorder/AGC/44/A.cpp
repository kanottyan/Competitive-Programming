#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> memo;
long long A;
long long B;
long long C; 
long long D;

long long rec(long long N){
    long long ans;

    if( memo.count(N) > 0 ){
        return memo[N];
    }

    if(N == 0){
        ans = 0;
        return memo[N] = ans; 
    }

    if(N == 1){
        ans = D;
        return memo[N] = ans; 
    }

    ans = 9e18;
    // all use D
    if( N < ans/D ){
        ans = N * D;
    }

    //2
    ans = min(ans, ( (rec(N/2) + A) + (N%2) * D) );
    if(N %2 != 0){
        ans = min(ans, ( (rec(N/2+1) + A) + ((N/2+1)*2- N)*D ) );
    }
    //3
    ans = min(ans, ( (rec(N/3) + B) + (N%3) * D) );
    if(N%3 != 0){
        ans = min(ans, ( (rec(N/3+1) + B) + ((N/3+1)*3- N)*D ) );
    }
    //5
    ans = min(ans, ( (rec(N/5) + C) + (N%5) * D) );
    if(N%5 != 0){
        ans = min(ans, ( (rec(N/5+1) + C) + ((N/5+1)*5- N)*D ) );
    }

    return memo[N] = ans; 
}


int main(){
    int T;
    cin >> T;
    
    for(int i=0; i<T; ++i){
        memo.clear();
        long long N;
        cin >> N >> A >> B >> C >> D;
        long long ans;
        ans = rec(N);
        cout << ans << endl;
    }
}








// const long long INF = 1e18;
// long long dp[4][10000];

// int main(){
//     long long N;
//     cin >> N;
//     long long A, B, C, D;
//     cin >> A >> B >> C >> D;

//     //init
//     long long num = D;
//     for(int j=1; j<=2*N; ++j){
//         dp[0][j] = num;
//         num += D;
//     }
//     for(int i=1; i<4; ++i){
//         for(int j=1; j<=2*N; ++j){
//             dp[i][j] = INF;
//         }
//     }

//     //配るdp
//     //other cases
//     for(int i=1; i<=3; ++i){
//         for(int j=1; j<=50; ++j){
//             //もらって
//             dp[i][j] = min(dp[i-1][j], dp[i][j]);
//             dp[i][j] = min(dp[i][j-1] +D, dp[i][j]);
//             dp[i][j] = min(dp[i][j+1] +D, dp[i][j]);

//             if(i == 1){
//                     //配る
//                     //can't use min !!  change later
//                     dp[i][j*2] = min(dp[i-1][j*2], dp[i][j*2]);
//                     dp[i][j*2] = min(dp[i][j*2], dp[i][j]+ A);
//                     dp[i][j*2] = min(dp[i][j*2], dp[i][j*2+1] + D);
//                     dp[i][j*2] = min(dp[i][j*2], dp[i][j*2-1] + D);

//                     //隣の更新
//                     dp[i][j*2+1] = min(dp[i][j*2+1], dp[i-1][j*2+1] );
//                     dp[i][j*2+1] = min(dp[i][j*2+1], dp[i][j*2] + D );

//                     dp[i][j*2-1] = min(dp[i][j*2-1], dp[i-1][j*2-1]);
//                     dp[i][j*2-1] = min(dp[i][j*2-1], dp[i][j*2-1] + D);
//             }else if(i == 2){
//                     //配る
//                     //can't use min !!  change later
//                     dp[i][j*3] = min(dp[i-1][j*3], dp[i][j*3]);
//                     dp[i][j*3] = min(dp[i][j*3], dp[i][j]+ B);
//                     dp[i][j*3] = min(dp[i][j*3], dp[i][j*3+1] + D);
//                     dp[i][j*3] = min(dp[i][j*3], dp[i][j*3-1] + D);

//                     //隣の更新
//                     dp[i][j*3+1] = min(dp[i][j*3+1], dp[i-1][j*3+1] );
//                     dp[i][j*3+1] = min(dp[i][j*3+1], dp[i][j*3] + D );

//                     dp[i][j*3-1] = min(dp[i][j*3-1], dp[i-1][j*3-1]);
//                     dp[i][j*3-1] = min(dp[i][j*3-1], dp[i][j*3-1] + D);
//             }else{
//                     //配る
//                     //can't use min !!  change later
//                     dp[i][j*5] = min(dp[i-1][j*5], dp[i][j*5]);
//                     dp[i][j*5] = min(dp[i][j*5], dp[i][j]+ C);
//                     dp[i][j*5] = min(dp[i][j*5], dp[i][j*5+1] + D);
//                     dp[i][j*5] = min(dp[i][j*5], dp[i][j*5-1] + D);

//                     //隣の更新
//                     dp[i][j*5+1] = min(dp[i][j*5+1], dp[i-1][j*5+1] );
//                     dp[i][j*5+1] = min(dp[i][j*5+1], dp[i][j*5] + D );

//                     dp[i][j*5-1] = min(dp[i][j*5-1], dp[i-1][j*5-1]);
//                     dp[i][j*5-1] = min(dp[i][j*5-1], dp[i][j*5-1] + D);
//             }
//         }
//     }

//     // long long res = 0;
//     // long long tmp = N;
//     // while(tmp > 0){

//     //     tmp /= 
//     // }

//     cout << dp[3][N] << endl;
// }
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

//確率の遷移
double dp[101][101][101];
double Ex[1000];


int main(){
    int A, B, C;
    cin >> A >> B >> C;

    dp[A][B][C] = 1.0;
    for(int a=A; a<100; ++a){
        for(int b=B; b<100; ++b){
            for(int c=C; c<100; ++c){
                double da = (double)a;
                double db = (double)b;
                double dc = (double)c;
                double bunbo = (da + db + dc);

                dp[a+1][b][c] += ( (da)/(bunbo)*dp[a][b][c]);
                dp[a][b+1][c] += ( (db)/(bunbo)*dp[a][b][c]);
                dp[a][b][c+1] += ( (dc)/(bunbo)*dp[a][b][c]);
            }
        }
    }

    int start = A + B + C;
    for(int b=0; b<100; ++b){
        for(int c=0; c<100; ++c){
            int num = 100+b+c-start;
            if( num <= 0 ) continue;
            Ex[num] += dp[100][b][c];
        }
    }

    for(int a=0; a<100; ++a){
        for(int b=0; b<100; ++b){
            int num = 100+a+b-start;
            if( num <= 0 ) continue;
            Ex[num] += dp[a][b][100];
        }
    }

    for(int a=0; a<100; ++a){
        for(int c=0; c<100; ++c){
            int num = 100+a+c-start;
            if( num <= 0 ) continue;
            Ex[num] += dp[a][100][c];
        }
    }

    double ans = 0;

    for(int i=0; i<1000; ++i){
        ans += i * Ex[i];
    }
    
    printf( "%.10f", ans );

    return 0;
}

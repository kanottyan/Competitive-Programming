#include <iostream>
#include <vector>

using namespace std;

long long dp[3100][3100];
//int dp[30][30];


int main(){
    int N;
    cin >> N;
    vector<int> a(N);

    for(int i=0; i<N; ++i){
        cin >> a[i];
    }

    for(int i=0; i <N; ++i){
        dp[i][i] = 0;
    }

    for(int len =1; len <=N; ++len){
        for(int i=0; i+len <= N; ++i){
            int j = i + len;

            //first
            if( (N-len)%2 == 0 ){
                //int one = dp[i+1][j] +a[i];
                //int two = dp[i][j-1] + a[j-1];
                dp[i][j] = max(dp[i+1][j] +a[i], dp[i][j-1] + a[j-1] );
            }else{
            //second
                //int one = dp[i+1][j] -a[i];
                //int two = dp[i][j-1] - a[j-1];
                dp[i][j] = min(dp[i+1][j] -a[i], dp[i][j-1] - a[j-1] );
            }
        }
    }

    cout << dp[0][N] << endl;
}
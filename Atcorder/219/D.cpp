#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// dp[i][j][k] : select till item i, the minimum  j,k required to be selected

int dp[310][310][310];
const int INF = 1<<30;

int main(){
    //init
    for(int i=0; i<310; ++i){
        for(int j=0; j<310; ++j){
            for(int k=0; k<310; ++k){
                dp[i][j][k] = INF;
            }
        }
    }    

    for(int i=0; i<310; ++i){
        dp[i][0][0] = 0;
    }

    int N; cin >> N;
    int X, Y; cin >> X >> Y;

    vector<pair<int, int>> vp(N);
    for(int i=0; i<N; ++i){
        int A, B; cin >> A >> B;
        vp[i] = {A, B};
    }


    for(int i=0; i<N; ++i){
        int A = vp[i].first;
        int B = vp[i].second;
        for(int j=0; j<310; ++j){
            for(int k=0; k<310; ++k){
                // don't choose the item
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                //select the item
                int nj = j+A; int nk = k+B;
                if(nj > 300) nj = 301;
                if(nk > 300) nk = 301;
                dp[i+1][nj][nk] = min(dp[i+1][nj][nk], dp[i][j][k]+1);
            }
        }
    }

    int ans = INF; 
    for(int j=X; j<310; ++j){
        for(int k=Y; k<310; ++k){
            ans = min(ans, dp[N][j][k]);
        }
    }
    if(ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

//dp[i][j] i個目まで見て和がj
//Aiが選ばれるときだけ、jにAiwを足す
int dp[3010][3010] = {0};
const int MOD = 998244353;

int main(){
    int N, S;
    cin >> N >> S;

    vector<int> a(N+1);

    for(int i=1; i<=N; ++i){
        cin >> a[i]; 
    }

    //init 
    dp[0][0] =1;
    for(int i=1; i<=N; ++i){
        for(int j=0; j<=S; ++j){
            //jが変わらない遷移が２個（1.Tに選ばれないと2.Tに選ばれるけどUに選ばれない）
            dp[i][j] = dp[i-1][j] *2;
            dp[i][j] %= MOD;
        }
        for(int j=0; j<=S; ++j){
            //jが変わる遷移が一個（Uに選ばれる）
            if(j + a[i] <= S){
                dp[i][j + a[i]] += dp[i-1][j];
                dp[i][j + a[i]] %= MOD;
            }
        }
    }

    cout << dp[N][S] << endl;;

}
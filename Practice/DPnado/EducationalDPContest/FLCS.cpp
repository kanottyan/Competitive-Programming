//https://atcoder.jp/contests/dp/tasks/dp_f

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[3100][3100];

int main(){
    string s, t;
    cin >> s >> t;

    for(int i=0; i<s.size(); ++i){
        dp[i][0] = 0;
    }

    for(int j=0; j<t.size(); ++j){
        dp[0][j] = 0;
    }

  //memset(dp, 0, sizeof(dp));    // kottinoga raku


    for(int i=0; i<s.size(); ++i){
        for(int j=0; j<t.size(); ++j){
            if(s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j] + 1);
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j+1]);

            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    //fukugen
    string res = "";
    int i = (int)s.size(); 
    int j = (int)t.size();

    while(i >0 && j > 0){
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }
    }


    //cout << dp[s.size()][t.size()] << endl;
    cout << res << endl;
}
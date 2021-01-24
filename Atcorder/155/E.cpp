#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//0繰り上がりなし, 1繰り上がりあり
long long dp[1000][2];
//long long dp[1000100][2];
const long long INF = 1LL << 61;

int main(){
    string money = "0";
    string s;
    cin >> s;

    money += s;

    long long n = money.size();
    long long ans = 0;

    //init
    for(int i=0; i< 1000; ++i){
        for(int j=0; j<2; ++j){
            dp[i][j] = INF;
        }
    }

    //後ろから数える
    int first = money[n-1] - '0';
    dp[n-1][0] = first;
    dp[n-1][1] = 10 - first;


    for(long long  i=n-2; i >= 0; --i){

        int num = money[i] - '0';

            //繰り上がりなし
            dp[i][0] = min(dp[i][0], dp[i+1][0] + num);
            dp[i][0] = min(dp[i][0], dp[i+1][1] + (num+1) );

            //繰り上がりあり
            dp[i][1] = min(dp[i][1], dp[i+1][0] + (10 - num) );
            dp[i][1] = min( dp[i][1], dp[i+1][1] + (10 - (num+1) ) );
    }

    cout << min(dp[0][0], dp[0][1]) << endl;
}

// #include <bits/stdc++.h>
// #define rep(i,n) for (int i = 0; i < (n); ++i)
// using namespace std;
// using ll = long long;
// using P = pair<int,int>;
// #define chmin(x,y) x = min(x,y)

// const int INF = 1001001001;
// int dp[1000005][2];

// int main() {
//   string s;
//   cin >> s;
//   reverse(s.begin(), s.end());
//   s += '0';
//   int n = s.size();
//   rep(i,n+1)rep(j,2) dp[i][j] = INF;
//   dp[0][0] = 0;
//   rep(i,n)rep(j,2) {
//     int x = s[i]-'0';
//     x += j;
//     if (x < 10) chmin(dp[i+1][0], dp[i][j]+x);
//     if (x > 0) chmin(dp[i+1][1], dp[i][j]+(10-x));
//   }
//   int ans = dp[n][0];
//   cout << ans << endl;
//   return 0;
// }

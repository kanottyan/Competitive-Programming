// #include<iostream>

// using namespace std;

// using ll = long long;
// const ll mod = 998244353;


// //ll dp[3030][3030][3];
// ll dp[10][10][3];

// int a[3030];
// int main(){
//     int n, k;
//     cin >> n >> k;
//     for(int i=0;i<n;i++)cin >> a[i];
//     dp[0][0][0] = 1;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=k;j++){
//             (dp[i+1][j][0] += dp[i][j][0]) %= mod;
//             (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
//             (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
//             if(j + a[i] <= k){
//                 (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
//                 (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
//             }
//         }
//     }
//     cout << dp[n][k][2] << endl;
// }


#include <iostream>
#include <vector>

using namespace std;

//int dp[3010][3010] = {0};
int dp[11][11] = {0};

const int MOD = 998244353;

int main(){
    int n, s;
    cin >> n >> s;

    vector<int> a(n);

    for(int i=0; i<n; ++i){
        cin >> a[i]; 
    }

    vector<int> q(s+1);

    int ans = 0;
    for(int i=0; i<n; ++i){
        q[0] += 1; //q += 1
        { // q *= (1 + x^a[i])
            vector<int> q2(s+1);
            for(int j=0; j<s+1; ++j){
                q2[j] += q[j];
                if(j+a[i] <= s){
                    q2[j+a[i]] += q[j];
                }
            }
            q = q2;
        }
        ans += q[s];
    }

    cout << ans << endl;;

}

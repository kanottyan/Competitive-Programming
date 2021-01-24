#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

//x 日目に、株の売却が終了した時点の所持金の最大値。
long long dp[90];

//dp
int main(){
    int N; cin >> N;

    pair<long long, long long> money_stock;

    vector<long long> stock_price(N+1);
    for(int i=1; i<=N; ++i){
        cin >> stock_price[i];
    }

    dp[1] = 1000;

    for(int i=2; i<=N; ++i){
        //i − 1 日目から何もしない場合
        dp[i] = dp[i-1];
        for(int j=1; j<=i-1; ++j){
            //j 日目に 全財産を使って株を買い、i 日目に株を全部売る場合
            long long stock_num = dp[j] / stock_price[j];
            long long money = dp[j] + (stock_price[i] - stock_price[j])* stock_num;
            dp[i] = max(dp[i], money);
        }

    }

    cout << dp[N] << endl;

}


// 貪欲法
// int main(){
//     int N; cin >> N;

//     vector<long long> stock_price(N+1);
//     for(int i=1; i<=N; ++i){
//         cin >> stock_price[i];
//     }

//     long long money = 1000;

//     for(int i=2; i<=N; ++i){
//         if(stock_price[i-1] < stock_price[i]){
//             long long amari = money%stock_price[i-1];
//             money += abs(stock_price[i-1] - stock_price[i]) * (money / stock_price[i-1]);
//             // money += amari;
//         }
//     }
//     cout << money << endl;
// }


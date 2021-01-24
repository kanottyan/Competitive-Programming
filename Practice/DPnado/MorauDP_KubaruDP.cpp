//https://www.tradingview.com/gopro/?share_your_love=Kanonoka5b

//解法 3: 個数制限なしナップサック DP
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 15;// 12 種類だが余裕をもつ
const int MAX_W = 110000;

int dp[MAX_N][MAX_W];

int main(){
    int W;
    cin >> W;

    vector<int> weight;
    for(int i = 1; i<=W; i *= 6) weight.push_back(i);
    for(int i = 9; i<=W; i *= 9) weight.push_back(i);
    int n = (int)weight.size();

    //DP init dp[i][0] = 0
    for (int i = 0; i < MAX_N; ++i) for (int w = 0; w < MAX_W; ++w) dp[i][w] = 1 << 29; // INF
    for(int i=0; i<=n; ++i) dp[i][0] = 0;

    //DP loop
    for(int i=0; i<n; ++i){
        for(int w=0; w<=W; ++w){
            dp[i+1][w] = min(dp[i][w], dp[i+1][w]);
            if(w >= weight[i]){
                dp[i + 1][w] = min(dp[i + 1][w], dp[i + 1][w - weight[i]] + 1);
            }
        }
    }
    cout << dp[n][W] << endl; 
}


// // 解法 2: BFS
// #include <iostream>
// #include <queue>

// using namespace std;
// const int MAX_N = 110000;

// int dp[MAX_N];

// int main(){
//     int N;
//     cin >> N;

//     //初期化　
//     for(int i=0; i<MAX_N; ++i)dp[i] = -1;
//     dp[0] = 0;
//     queue<int> que;
//     que.push(0);

//     //BFS
//     while(!que.empty()){
//         int v = que.front();
//         que.pop();

//         for(int pow6 =1; v+pow6 <=N; pow6 *=6 ){
//             if(dp[v+pow6] == -1){
//                 dp[v+pow6] = dp[v] +1;
//                 que.push(v+pow6);
//             }
//         }

//         for(int pow9 =1; v+pow9 <=N; pow9 *=9 ){
//             if(dp[v+pow9] == -1){
//                 dp[v+pow9] = dp[v] + 1;
//                 que.push(v+pow9);
//             }
//         }
//     }

//     cout << dp[N] << endl;
// }


// //解法 1-2-1: ボトムアップにループ回す DP(配るDP)
// #include <iostream>
// using namespace std;

// const int MAX_N = 110000;
// int dp[MAX_N];

// int main(){
//     int N;
//     cin >> N;

//     for (int i = 0; i < MAX_N; ++i) dp[i] = N; // INF の気持ち
//     dp[0] = 0;

//     // 配る DP --- dp[n]を次に与える
//     for(int n=0; n<=N; ++n){
//         for(int pow6 = 1; n+pow6 <= N; pow6 *= 6){
//             dp[n+pow6] = min(dp[n+pow6], dp[n]+1);
//         }

//         for(int pow9 = 1; n+pow9 <= N; pow9 *= 9){
//             dp[n+pow9] = min(dp[n+pow9], dp[n] + 1);
//         }
//     }
//     cout << dp[N] << endl;
// }


// //解法 1-2-1: ボトムアップにループ回す DP(もらうDP)
// #include <iostream>
// using namespace std;

// const int MAX_N = 110000;
// int dp[MAX_N];

// int main(){
//     int N;
//     cin >> N;

//     dp[0] = 0;
//     for(int i=0; i<MAX_N; ++i) dp[i] = N;

//     // 貰う DP --- dp[n] に遷移を集める
//     for(int n=1; n<=N; ++n){
//         for(int pow6 = 1; pow6 <= n; pow6 *= 6){
//             dp[n] = min(dp[n-pow6]+1, dp[n] );
//         }

//         for(int pow9 = 1; pow9 <= n; pow9 *= 9){
//             dp[n] = min(dp[n-pow9]+1, dp[n] );
//         }
//     }
//     cout << dp[N] << endl;
// }


//解法 1-1: トップダウンに N を降下していくメモ化再帰
// #include <iostream>
// using namespace std;

// const int MAX_N = 110000;
// int memo[MAX_N]; // memo[i] が i についての答え


// int rec(int n){
//     if(n == 0) return 0; // 終端条件
//     if(memo[n] != -1 ) return memo[n]; // すでに探索済みならリターン

//     int res = n; // means the maximum value

//     // 1, 6, 6^2, ..., を試す (n を超えない範囲で)
//     for(int pow6 = 1; pow6 <= n; pow6 *= 6){
//         res = min(res, rec(n- pow6) +1);
//     }

//     // 1, 9, 9^2, ..., を試す (n を超えない範囲で)
//     for(int pow9 = 1; pow9 <= n; pow9 *= 9){
//         res = min(res, rec(n-pow9)+1);
//     }

//     return memo[n] = res;
// }

// int main(){
//     int N;
//     cin >> N;

//     for(int i=0; i<MAX_N; ++i) memo[i] = -1;
//     cout << rec(N) << endl;

// }
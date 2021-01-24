//https://atcoder.jp/contests/dp/tasks/dp_d

//N個の品物があり、i番目の品物のそれぞれ重さと価値が weight[i],value[i]で与えられます (i=0,1,...,N−1 )。
//これらの品物から重さの総和が Wを超えないように選んだときの、価値の総和の最大値

// 入力例
// 4 6
// 3 6
// 1 3
// 2 1
// 4 85

//out --> 88

//通常DP解
#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main(){
    long long N, W;
    cin >> N >> W;

    vector<long long> w(N);
    vector<long long> v(N);

    for(int i=0; i<N; ++i) cin >> w[i] >> v[i];
    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));

    for(int i=0; i<N; ++i){
        for(int j=0; j<W+1; ++j){
            //配るDP
            //アイテムを使わない
            chmax(dp[i+1][j], dp[i][j]);
            //アイテムを使う
            if(j+w[i] <= W)  chmax(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}



//---------------------

//インライン化、dp配列一つのみ。Wは重複なしの場合は後ろから数える

// #include <iostream>
// #include <vector>
// using namespace std;

// template<class T> void chmax(T &a, T b) {
//     if (a < b) a = b;
// }

// int main() {
//     int N, W;
//     cin >> N >> W;
//     vector<int> weight(N), value(N);
//     for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

// vector<long long> dp(W+1, 0);
// for (int i = 0; i < N; ++i) {
//    for (int w = W; w>=0 ; --w) {
//        if (w - weight[i] >= 0) {
//            chmax(dp[w], dp[w - weight[i]] + value[i]);
//        }
//    }
// }

//     cout << dp[W] << endl;
// }

//-------------------------

//より汎用的に使える、メモリ節約テクニック
//「更新前」と「更新後」の配列は別のものとする
// #include <iostream>
// #include <vector>

// using namespace std;

// template<class T> void chmax(T &a, T b){
//     if(b > a) a = b;
// }

// int main(){
//     int N, W;
//     cin >> N >> W;
//     vector<int> weight(N), value(N);

//     for(int i=0; i<N; ++i) cin >> weight[i] >> value[i];

//     // N のところを2にする
//     vector<vector<long long> > dp(2, vector<long long>(W+1, 0));
//     for(int i=0; i < N; ++i){
//         for(int w=0; w <=W; ++w){
//             chmax(dp[(i+1) %2][w], dp[i%2][w]);
//             if(w + weight[i] <= W){
//                 chmax(dp[(i+1)%2][w + weight[i]], dp[i%2][w] + value[i]);
//             }
//         }
//         //次回更新配列を初期化
//         dp[i%2].assign(W+1, 0);
//     }
//     cout << dp[N%2][W] << endl;
// }
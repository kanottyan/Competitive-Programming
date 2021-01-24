#include <iostream>
#include <bitset>

using namespace std;

const int INF = 100100100;

//input
int N;
int dist[5][5];

/*memo cache*/
int dp[(1<<5)][5]; // make a big dp table

int rec(int bit, int v){
    //if already searched, then return the dp distance
    if(dp[bit][v] != -1) return dp[bit][v];

    //init value
    if( bit == (1<<v)){
        return dp[bit][v] = 0;
    }

    //var to store res
    int res = INF;

    //bit without v;
    int prev_bit = bit & ~(1<<v);

    //all seach from place goes to v
    for(int u=0; u <N; ++u){
        // if u is not in prev_bit then don't do anything
        if(!(prev_bit & (1<<u))) continue; 

        if(res > rec(prev_bit, u) + dist[u][v]){
            res = rec(prev_bit, u) + dist[u][v];
        }
    }
    return dp[bit][v] = res; //memo cache
}

int main(){
    //input 
    cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> dist[i][j];
        }
    }

    // init dp table as -1. if the value is not -1 it means the place is already searched.
    for(int bit=0; bit<(1<<N) ; ++bit){
        for(int j=0; j<N; ++j){
            dp[bit][j] = -1;
        }
    }

    // TSL search.
    int res = INF;
    for(int v=0; v<N; ++v){
        if(res > rec( (1<<N)-1, v )){
            res = rec( (1<<N)-1, v );
        }
    }
    cout << res << endl;
}

// 【数値例】
// 1) 
// 　n=3

// 　dist=

// 0 5 2
// 5 0 4
// 2 4 0
// 　答え: 6 (0 -> 2 -> 1 の順にだどると 6 秒で行けます)
// 2)
// 　n=4

// 　dist=

// 0 8 7 3
// 8 0 9 1
// 7 9 0 4
// 3 1 4 0
// 　答え: 11 (1 -> 3 -> 0 -> 2 の順にたどると 11 秒で行けます)



// //2. for文で解く方法
// int main(){
//     int n;
//     cin >> n;
//     vector<int> x(n), y(n), z(n);
//     for(int i=0; i<n; ++i) cin >> x[i] >> y[i] >> z[i];

//     int n2 = 1 << n;
//     //dp[S][v] := いままで　訪れた頂点集合がS。今いる頂点がVのときの最小コスト
//     vector<vector<int>> dp(n2, vector<int>(n, INF));
//     vector<vector<int>> dist(n, vector<int>(n));
//     for(int i=0; i<n; ++i){
//         for(int j=0; j<n; ++j){
//             int now = abs(x[i] - x[j]);
//             now += abs(y[i] - y[j]);
//             now += max(0, z[j] - z[i]);
//             dist[i][j] = now;
//         }
//     }

//     //初期値: 0から行くときの距離
//     for(int i=0; i<n; ++i){
//         if(i == 0) continue;
//         dp[1<<i][i] = dist[0][i];
//     }
//     for(int i=0; i<n2; ++i){
//         for(int j=0; j<n; ++j){
//             //そもそもその桁をビットがないとだめなので
//             //iにjが入ってなかったらだめの意味
//             if( ~i>>j&1 ) continue;
//             //jからkに向かう
//             for(int k=0; k<n; ++k){
//                 //kがiに含まれてたらだめ
//                 if(i>>k&1)continue;
//                 //　(i|1<<k)はiのk桁目に１を足す
//                 chmin(dp[i|1<<k][k], dp[i][j] + dist[j][k] );
//             }
//         }
//     }
//     cout << dp[n2-1][0] << endl;
// }

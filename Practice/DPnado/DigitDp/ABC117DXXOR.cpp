//https://atcoder.jp/contests/abc117/tasks/abc117_d
//https://drken1215.hatenablog.com/entry/2019/02/03/224200

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1;} return 0; }

long long dp[100][2];
const int MAX_DIGIT = 5;


// dp[ i ][ smaller ] := X
// X を上から i 桁目まで決めたとき、それを K
// K の上から i 桁目までと比較したときに、
// smaller = 0 のとき、K とちょうど一致する場合
// smaller = 1 のとき、K よりも小さくなっている場合についての、スコアの最大値

int main(){
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i = 0 ; i < N; ++i) cin >> A[i];

    memset(dp, -1, sizeof(dp)); // -1に初期化
    dp[0][0] = 0;
    for(int d= 0; d < MAX_DIGIT; ++d){
        long long mask = 1LL << (MAX_DIGIT - d - 1);

        // A で元々 d 桁目にビットが立っているものの個数
        int num = 0;

        for(int i=0; i < N; ++i){
            if(A[i] & mask ) ++ num;
        }

        // X の d 桁目を 0, 1 にしたときのコスト
        long long cost0 = mask * num;
        long long cost1 = mask * (N - num);

        //smaller --> smaller 
        if(dp[d][1] != -1 ){
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1)); // 0でも1でも可能
        }

        //exat --> smaller
        if(dp[d][0] != -1){
            // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
            if(K & mask){
            chmax(dp[d+1][1], dp[d][0] + cost0);                
            }
        }

        //exact -- > exact
        if(dp[d][0] != -1){
            if(K & mask){
                chmax(dp[d+1][0], dp[d][0] + cost1);
            }else{
                chmax(dp[d+1][0], dp[d][0] + cost0);
            }
        }
    }

    cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}
// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// int binary_digit_one_num[100]; //i桁目の値が1の個数;


// int main(){
//     int N; 
//     long long K;
//     cin >> N >> K;

//     vector<long long> a(N);

//     for(int i=0; i<N; ++i){
//         cin >> a[i];
//     }

//     //10進数を2進数にして、各桁で1があるところを記録
//     for(int i=0; i<N; ++i){
//         long long NUM = a[i];
//         int keta = 0;
//         int cnt = 0;

//         while( NUM > 0 ){
//             if(NUM&1){
//                 keta = cnt;
//                 binary_digit_one_num[keta]++;
//             } 
//             NUM >>= 1;
//             cnt++;
//         }
//     }

//     int max_keta = 0;
//     int cnt = 0;
//     long long k = K;
//     while(k > 0){
//         if(k & 1) max_keta = cnt;
//         k >>= 1;
//         cnt++;
//     }

//     long long candidate = 0;
//     for(int keta=max_keta; keta>=0; --keta){
//         if( N %2 == 0){
//             // 0が多いので1を選択
//             if( binary_digit_one_num[keta] < N/2 ){
//                 long long tmp = candidate + pow(2, keta);
//                 if(tmp <= K){
//                     candidate = tmp;
//                 }
//             }
//         }else{
//             // 0が多いので1を選択
//             if( binary_digit_one_num[keta] < N/2 + 1 ){
//                 long long tmp = candidate + pow(2, keta);
//                 if(tmp <= K){
//                     candidate = tmp;
//                 }
//             }
//         }
//     }

//     long long ans = 0;
//     for(int i=0; i<N; ++i){
//         ans += candidate ^ a[i];
//     }

//     cout << ans << endl;
// }
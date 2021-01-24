#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int pcnt(int x){
    return __builtin_popcount(x);
}

int f(int x){
    if(x ==0) return 0;
    return f(x%pcnt(x)) +1;
}

int main(){
    int n ;
    cin >> n;
    string s; 
    cin >> s;

    vector<int> x(n);

    for(int i=0; i<n; ++i){
        x[i] = s[i] - '0';
    }

    int pc = 0;

    for(int i=0; i<n; ++i) pc += x[i];

    vector<int> ans(n);
    for(int b=0; b<2; ++b){
        int npc = pc;
        if(b == 0) npc++; else npc--;
        if( npc <= 0) continue;
        //もとの割ったあまり, 2進数を10進数に直すテクニックにmodをしたもの.
        int r0 = 0;
        for(int i=0; i<n; ++i){
            r0 = (r0*2)%npc;
            r0 += x[i];
        }

        //桁
        int k = 1;

        for(int i=n-1; i>= 0; --i){
            if(x[i] == b){
                int r = r0;
                if(b==0) r = (r+k)%npc;
                else r = (r-k+npc)%npc;
                ans[i] = f(r) + 1;
            }
            k = (k*2) %npc;
        }
    }

    for(int i=0; i<n; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}


//自己流解法
// // a^n mod を計算する
// long long modpow(long long a, long long n, long long mod) {
//     long long res = 1;
//     while (n > 0) {
//         if (n & 1) res = res * a % mod;
//         a = a * a % mod;
//         n >>= 1;
//     }
//     return res;
// }

// long long popcount(long long n){
//     return __builtin_popcountll(n);
// }

// long long count_process(long long N){
//     if(N == 1) return 1;
//     if(N == 0) return 0;

//     return count_process(N % popcount(N)) + 1;
// }


// int main(){
//     int N;
//     string X;
//     cin >> N >> X;


//     //Xに1が何個あるか求める
//     long long one_counter = 0;
//     for(int i=0; i<N; ++i){
//         if( X[i] == '1' ) one_counter++;
//     }

//     vector<long long> original_mod_cumsum_plus_one(N + 1);
//     vector<long long> original_mod_cumsum_minus_one(N + 1);

//     //mod内でで合計を計算する
//     for(int i=0; i<N; ++i){
//         if(X[i] == '1'){
//             long long keta = modpow(2, (N-1-i), one_counter+1);
//             original_mod_cumsum_plus_one[N-1-i] = keta;
//         }
//     }
//     long long original_m_plus = 0 ;
//     for(int i=0; i<N; ++i){
//         original_m_plus += original_mod_cumsum_plus_one[i];
//         original_m_plus %= (one_counter+1);
//     }

//     long long original_m_minus = 0 ;
//     //もし1が1つしかないとcount -1 が0 になってREになるので例外処理。
//     // 1が一つもない場合はそもそもこのケースがありえないので, one_counter == 1の場合のみ処理する
//     if(one_counter > 1){
//         for(int i=0; i<N; ++i){
//             if(X[i] == '1'){
//                 long long keta = modpow(2, (N-1-i), one_counter-1);
//                 original_mod_cumsum_minus_one[N-1-i] = keta;
//             }
//         }
//         for(int i=0; i<N; ++i){
//             original_m_minus += original_mod_cumsum_minus_one[i];
//             original_m_minus %= (one_counter-1);
//         }
//     }

//     //forで各桁に対して操作
//     for(int i=0; i<N; ++i){
//         long long res;
//         long long tmp_m_minus = original_m_minus;
//         long long tmp_m_plus = original_m_plus;

//         //0に反転する
//         if(X[i] == '1'){
//             if(one_counter == 1){
//                 res = 0;
//             }else{
//                 tmp_m_minus -= modpow(2, (N-1-i), one_counter-1);
//                 if(tmp_m_minus <= 0){
//                     tmp_m_minus += (one_counter-1);
//                     tmp_m_minus %= (one_counter-1);
//                 }
//                 long long tmp_one_counter = one_counter - 1 ;
//                 tmp_m_minus %= tmp_one_counter;

//                 res = count_process(tmp_m_minus) + 1;
//             }

//         }else{
//             //1に反転
//             tmp_m_plus += modpow(2, (N-1-i), one_counter+1);
//             long long tmp_one_counter = one_counter+1;
//             tmp_m_plus %= tmp_one_counter;

//             res = count_process(tmp_m_plus) + 1;

//         }
//         cout << res << endl;
//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int divceil(int a, int b){
    return (a+b-1)/b;
}

int main(){
    long long k, q;
    cin >> k >>q;

    vector<long long> d(k);
    for(int i=0; i<k; ++i) cin >> d[i];

    for(int _=0; _<q; ++_){
        int n, x , m;
        cin >> n >> x >> m;
        //最後の項
        long long last = x;
        //0が何個なのか
        long long eq = 0;
        //diが何回たされるか
        for(int i=0; i<k; ++i){
            long long num = divceil(n-1-i, k);
            last += (d[i]%m)*num;
            if(d[i]%m == 0) eq += num;
        }
        //答え 全体 - (>)
        long long ans = (n-1) - (last/m -x/m);
        //イコールの場合も引く
        ans -= eq;
        cout << ans << endl;
    }
    return 0;
}

// int main(){
//     long long k , q;
//     cin >> k >> q;
//     vector<long long> d(k);
//     for(int i=0; i<k; ++i){
//         cin >> d[i];
//     }

//     for(int _=0; _<q; ++_){
//         long long n, x, m;
//         cin >> n >> x >> m;

//         int first_num = x % m;
//         int loop_cnt = 1;

//         int prev = first_num;
//         int new_num;
//         bool flag = true;

//         vector<long long> d_mod(k);
//         for(int i=0; i<k; ++i){
//             d_mod[i] = d[i] %m;
//         }

//         if(k >= n){
//             loop_cnt = 1;
//         }else{
//             while(flag){
//                 for(int i=0; i<k; ++i){
//                     new_num = (prev + d_mod[i])%m;

//                     if(i == k-1 && new_num == first_num){
//                         flag = false;
//                         loop_cnt--;
//                     } 
//                     prev = new_num;
//                 }
//                 loop_cnt++;
//             }
//         }

//         //何回ループしているのか保存
//         long long loop_num = loop_cnt * k;
//         long long ans = 0;

//         vector<long long> d_new(loop_num+1);

//         for(int i=1; i<loop_num; ++i){
//             d_new[i] = (d_new[i-1] + d_mod[(i-1)%k])%m;
//         }

//         for(int i=1; i<loop_num; ++i){
//             if(d_new[i-1] < d_new[i]) ans++;
//         }


//         if(loop_num < k){
//             cout << ans << endl;
//         }else{
//             long long times = n/loop_num;
//             long long rest = (n%loop_num) -1;
//             ans *= times;
//             for(int i=1; i<rest; ++i){
//                 if(d_new[i-1] < d_new[i]) ans++;
//             }
//             cout << ans << endl;
//         }

//     }
// }

    // vector<vector<long long>> d_mod(5010, vector<long long>(k));

    // for(int i=1; i<=5000; ++i){
    //     for(int j=0; j<k; ++j){
    //         d_mod[i][j] = d[j] % i;
    //     }
    // }


        // //とりあえずmodを考えずにやろう
        // vector<long long> d_new(n);
        // d_new[0] = x % m;

        
        // for(int i=1; i<n; ++i){
        //     d_new[i] = (d_new[i-1] + d_mod[m][(i-1)%k])%m;
        // }

        // long long ans = 0;
        // for(int i=1; i<n; ++i){
        //     if(d_new[i-1] < d_new[i]) ans++;
        // }

        // cout << ans << endl;

// 7 3
// 27 18 28 18 28 46 1000000000
// 10000 1 7
// 10000 2 10
// 10000 3 12

//ans
// 2245
// 2143
// 5595
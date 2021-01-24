#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
const int MOD = 1e9+7;
const long long INF = 1LL << 61;

int main(){
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    vector<long long> plus;
    vector<long long> minus;

    for(int i=0; i<N; ++i){
        if(A[i] <= 0) minus.push_back(A[i]);
        else plus.push_back(A[i]);
    }

    int plus_len = plus.size();
    int minus_len = minus.size();

    //積が正かを確認
    bool ok = false;

    if( plus_len > 0){
        if(N ==K) ok = (minus_len % 2 == 0);
        else ok = true;
    }
    else{
        if(K % 2 == 0) ok = true;
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    priority_queue<pair<pair<long long, int>, pair<long long, long long>>> group_agg;

    //絶対値順に並び替え
    sort(A.begin(), A.end(), [&](long long a, long long b){return abs(a) < abs(b);} );

    long long ans = 1;
    if(!ok){
        //正にできない場合、負になるので、絶対値が小さい順にとる
        for(int i=0; i<K; ++i){
            ans *= A[i];
            ans %= MOD;
        }
    }else{
        //正の場合はKが奇数なら正の数で一番大きいのをまず取る
        if(K%2 == 1){
            long long biggest = plus.back();
            ans *= biggest;
            ans %= MOD;
            plus.pop_back();
        }
        //Kが偶数ならあとは正と負で大きい順に大きいやつを２つ取る。
        int plus_idx = 0;
        int minus_idx = 0;
        sort(plus.rbegin(), plus.rend());

        for(int i=0; i<K/2; ++i){
            if( plus_idx+2 <= plus.size() ){            
                long long p1 = plus[plus_idx];
                plus_idx++;
                long long p2 = plus[plus_idx];
                plus_idx++;
                group_agg.push({{abs(p1) * abs(p2), 0} , {p1, p2}} );
            }
            if( minus_idx+2 <= minus.size()){
                long long m1 = minus[minus_idx];
                minus_idx++;
                long long m2 = minus[minus_idx];
                minus_idx++;
                group_agg.push({ {abs(m1) * abs(m2), 1} ,{m1, m2}});
            }
        }

        for(int i=0; i<K/2; ++i){
            auto tmp_pair = group_agg.top();
            group_agg.pop();
            long long tmp_sum = (tmp_pair.second.first * tmp_pair.second.second)%MOD;
            ans *= tmp_sum;
            ans %= MOD;
        }
    }

    if(ans <0){
        ans += MOD;
    }

    cout << ans << endl;
}


// int main(){
//     int N, K;
//     cin >> N >> K;

//     vector<long long> A(N);
//     for(int i=0; i<N; ++i){
//         cin >> A[i];
//     }
//     sort(A.begin(), A.end());

//     vector<long long> plus;
//     vector<long long> minus;
//     vector<long long> inv_minus;

//     priority_queue<pair<pair<long long, int>, pair<long long, long long>>> two_group_agg;

//     priority_queue<pair<pair<long long,int>, pair<long long,long long>>, 
//                         vector<pair<pair<long long,int>, pair<long long,long long>>>, 
//                         greater<pair<pair<long long,int>, pair<long long,long long>>>> two_group_agg_inv;

//     for(int i=0; i<N; ++i){
//         if(A[i] <= 0){
//             minus.push_back(A[i]);
//             inv_minus.push_back(A[i]);
//         }else{
//             plus.push_back(A[i]);
//         }
//     }

//     sort(plus.rbegin(), plus.rend());
//     sort(minus.begin(), minus.end());
//     sort(inv_minus.rbegin(), inv_minus.rend());


//     int plus_idx = 0;
//     int minus_idx = 0;
//     int inv_minus_idx = 0;
//     int two_counter = K/2;

//     long long ans = 1;
//     long long ans_inv = 1;

//     for(int i=0; i<two_counter; ++i){
//         if( plus_idx+2 <= plus.size() ){            
//             long long p1 = plus[plus_idx];
//             plus_idx++;
//             long long p2 = plus[plus_idx];
//             plus_idx++;
//             two_group_agg.push({{abs(p1) * abs(p2), 0} , {p1, p2}} );
//             two_group_agg_inv.push({{abs(p1) * abs(p2), 0}, {p1, p2}} );
//         }
//         if( minus_idx+2 <= minus.size()){
//             long long m1 = minus[minus_idx];
//             minus_idx++;
//             long long m2 = minus[minus_idx];
//             minus_idx++;
//             two_group_agg.push({ {abs(m1) * abs(m2), 1} ,{m1, m2}});
//         }
//         if( inv_minus_idx+2 <= inv_minus.size()){
//             long long im1 = inv_minus[inv_minus_idx];
//             inv_minus_idx++;
//             long long im2 = inv_minus[inv_minus_idx];
//             inv_minus_idx++;
//             two_group_agg_inv.push({ {abs(im1) * abs(im2), 1} ,{im1, im2}});
//         }
//     }


//     plus_idx = 0;
//     minus_idx = 0;


//     inv_minus_idx = 0;

//     for(int i = 0; i < two_counter; ++i){
//         auto tmp_pair = two_group_agg.top();
//         if( tmp_pair.first.second == 0) plus_idx += 2;
//         if( tmp_pair.first.second == 1) minus_idx += 2;

//         two_group_agg.pop();
//         long long tmp_sum = (tmp_pair.second.first * tmp_pair.second.second)%MOD;
//         ans *= tmp_sum;
//         ans %= MOD;
//     }

//     for(int i = 0; i < two_counter; ++i){
//         auto tmp_pair = two_group_agg_inv.top();
//         if( tmp_pair.first.second == 1) inv_minus_idx += 2;

//         two_group_agg_inv.pop();
//         long long tmp_sum = (tmp_pair.second.first * tmp_pair.second.second)%MOD;
//         ans_inv *= tmp_sum;
//         ans_inv %= MOD;
//     }

//     int last = K%2;
//     if(N == K){
//         ans = 1;
//         for(int i=0; i<N; ++i){
//             ans *= A[i];
//             ans %= MOD; 
//         }
//         if(ans <0){
//             ans += MOD;
//         }
//         cout << ans << endl;
//         return 0;
//     }

//     if(last){
//         if( plus_idx < plus.size() && minus_idx >= minus.size() ){
//             long long tmp1 = ans * plus[plus_idx];
//             tmp1 %= MOD;
//             ans = tmp1;
//         }else if(plus_idx >= plus.size() && minus_idx < minus.size() ){
//             long long tmp2 = ans_inv * inv_minus[inv_minus_idx];
//             tmp2 %= MOD;
//             ans = tmp2;
//         }else if( plus_idx < plus.size() && minus_idx < minus.size() ){
//             long long tmp1 = ans * plus[plus_idx];
//             tmp1 %= MOD;
//             long long tmp2 = ans_inv * inv_minus[inv_minus_idx];
//             tmp2 %= MOD;
//             // long long tmp3 = ans * minus.top();
//             // tmp3 %= MOD;
//             // long long tmp4 = ans_inv * minus.top();
//             // tmp4 %= MOD;
//             // long long tmp5 = ans * inv_minus.top();
//             // tmp5 %= MOD;

//             ans = max(tmp1, tmp2);
//             // ans = max(ans, tmp3);
//             // ans = max(ans, tmp4);
//             // ans = max(ans, tmp5);
//         }
//     }

//     if(ans <0){
//         ans += MOD;
//         ans %= MOD;
//     }

//     cout << ans << endl;
// }
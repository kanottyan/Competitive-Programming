#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x, m;
    cin >> n >> x >> m;

    vector<int> id(m, -1);
    vector<int> a;
    int len = 0;
    long long tot = 0;
    while( id[x] == -1){
        a.push_back(x);
        id[x] = len;
        len++;
        tot += x;
        x = (x * x)%m;
    }

    //周期の長さ
    int c = len - id[x];
    //周期の和
    long long s = 0;
    for(int i=id[x]; i < len; ++i){
        s += a[i];
    }

    long long ans =0;
    //周期する前に終わる場合
    if( n <= len){
        for(int i=0; i<n; ++i){
            ans += a[i];
        }
    }else{
    //周期する場合
        //最初のところの一周するまで。
        ans += tot;
        n -= len;
        //周期分
        ans += s*(n/c);
        //周期後の残り
        n %= c;
        //を足す
        for(int i=0; i<n; ++i){
            ans += a[id[x] + i];
        }
    }

    cout << ans << endl;
}

// int main(){

//     set<long long> s;
//     vector<long long> cycle_order;
//     long long N; cin >> N;
//     long long X, M; cin >> X >> M;

//     //cycleを見つける
//     bool is_cycle = false;
//     long long current_num = X;
//     long long cycle_start_num = -1;

//     //あと何回行動できるか
//     long long rest = N;
//     long long ans = 0;

//     for(long long i=0; i<N; ++i){
//         //ゼロなら以降ずっとゼロなのでブレイク
//         if(current_num == 0){
//             break;
//         }
//         //サイクルしたらブレイク
//         if(s.count(current_num) > 0){
//             is_cycle = true;
//             cycle_start_num = current_num;
//             break;
//         }
//         s.insert(current_num);
//         cycle_order.push_back(current_num);
//         //次の値
//         current_num = current_num * current_num;
//         current_num %= M;
//     }


//     //サイクルがない場合、またはゼロが来た場合10
//     if(is_cycle == false){
//         for(long long i=0; i<cycle_order.size(); ++i){
//             ans += cycle_order[i];
//         }
//     }else{
//         //サイクルの場所を復元する
//         vector<long long> cycle;
//         bool start = false;
//         for(long long i=0; i<cycle_order.size(); ++i){
//             if(start == false){
//                 if( cycle_order[i] != cycle_start_num ){
//                     ans += cycle_order[i];
//                     rest--;
//                     continue;
//                 } 
//                 cycle.push_back(cycle_start_num);
//                 start = true;
//             }else{

//                 if(cycle_order[i] == cycle_start_num){
//                     break;
//                 }else{
//                     cycle.push_back(cycle_order[i]);
//                 }
//             }
//         }

//         //サイクルの長さ
//         long long cycle_size= cycle.size();
//         //何回サイクルできるか
//         long long repeat = rest/cycle_size;
//         //サイクルの和
//         long long cycle_sum = 0;
//         for(int s=0; s<cycle_size; ++s){
//             cycle_sum += cycle[s];
//         }
//         //答えに加える
//         ans += (cycle_sum * repeat);

//         //サイクル後の残り回数
//         rest %= cycle_size;

//         int idx = 0;
//         while(rest){
//             ans += cycle[idx];
//             idx++;
//             rest--;
//         }
//     }

//     cout << ans << endl;

// }
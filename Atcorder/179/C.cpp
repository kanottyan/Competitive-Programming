#include <bits/stdc++.h>
using namespace std;


// vector<long long> enum_divisors(long long N) {
//     vector<long long> res;
//     for (long long i = 1; i * i <= N; ++i) {
//         if (N % i == 0) {
//             res.push_back(i);
//             // 重複しないならば i の相方である N/i も push
//             if (N/i != i) res.push_back(N/i);
//         }
//     }
//     // 小さい順に並び替える
//     //sort(res.begin(), res.end());
//     return res;
// }


int main(){
    long long N; cin >> N;

    vector<long long> cnt(N+1, 1);
    for(int i=2; i<=N-1; ++i){
        for(int j=i; j<=N-1; j += i){
            cnt[j]++;
        }
    }
    long long ans = 0;
    for(int i=1; i<=N-1; ++i){
        ans += cnt[i];
    }

    cout << ans << endl;

    //     long long kake_count = 0;

    // for(int i=1; i<=N-1; ++i){
    //     long long kakeru = i;
    //     long long tasu = N-1;
    //     // if(kakeru == 1){
    //     //     kake_count +=1;
    //     // }else{
    //     //     auto res = enum_divisors(kakeru);
    //     //     kake_count += res.size();
    //     // }
    // }

    // cout << kake_count << endl;

}
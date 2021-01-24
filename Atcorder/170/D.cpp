#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

const long long num = 1e6 + 10;
bool can_devid[num] = {false};
//bool can_devid[100];

int main(){
    long long N;
    cin >> N;

    set<long long> s;
    set<long long> ng;

    for(long long i=0; i<N; ++i){
        long long a;
        cin >> a;

        if( s.count(a) > 0 ){
            ng.insert(a);
        }
        
        s.insert(a);
    }

    set<long long> ans;
    ans.clear();
    for(long long i: s){
        if(can_devid[i] == false && ng.count(i) == 0){
            ans.insert(i);
        }
        for(long long j=i*2; j<=num; j += i){
            can_devid[j] = true;
        }
    }


    cout << ans.size() << endl;
}

// int main(){
//     int N;
//     cin >> N;
//     vector<long long> a(N);

//     for(int i=0; i<N; ++i){
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end());

//     int ans = 0;
//     unordered_map<long long, long long> mp;

//     for(int i=0; i<N; ++i){
//         // const auto& res = prime_factorize(a[i]);

//         // bool can_devid = false;

//         // for(auto p_ex: res){
//         //     //存在しない場合
//         //     if( mp.count(p_ex.first) > 0 ){
//         //         can_devid = true;
//         //         break;
//         //     }

//         //     // //存在して取替必要
//         //     // if( mp[p_ex.first] > p_ex.second ){
//         //     //     can_devid = false;
//         //     //     need_replace = true;
//         //     // }
//         // }

//         // if(!can_devid){
//         //     ans++;
//         //     for(auto p_ex: res){
//         //         mp[p_ex.first] = p_ex.second;
//         //     }
//         // }
//     }


//     cout << ans << endl;
// }
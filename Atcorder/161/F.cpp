#include <iostream>
#include <vector>

using namespace std;

vector<long long> enum_divisors(long long N){
    vector<long long> res;
    for(long long i=1; i*i <= N; ++i){
        if(N % i == 0){
            res.push_back(i);

            //重複しないならそれも入れる
            if(N/i != i) res.push_back(N/i);
        }
    }
    //小さい順に並べる
    //sort(res.begin(), res.end());
    return res;
}

// bool can_be_one( long long N, long long K){
//     if(K == 1) return false;

//     while( N % K == 0){
//         N /= K;
//     }

//     if(N == 1 || N % K == 1) return true;
//     else return false;
// }

int main(){
    long long N;
    cin >> N;

    // debug
    // for(long long i=2; i<=N; ++i){
    //     long long n = N;
    //     while(n >1){
    //         if(n %i == 0){
    //             n /= i;
    //         }else{
    //             n = n -i;
    //         }
    //     }
    //     if( n == 1) cout << i << endl;
    // }

    long long cnt = 0;
    for(long long x : enum_divisors(N)){
        if( x == 1) continue;
        long long tmp = N;
        while(tmp%x == 0)tmp /= x;
        tmp %= x;
        if(tmp == 1) cnt++;
    }

    vector<long long> nums_mod1 = enum_divisors(N-1);
    cnt += nums_mod1.size() - 1;

    cout << cnt << endl;

}
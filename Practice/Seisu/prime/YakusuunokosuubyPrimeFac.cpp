//https://atcoder.jp/contests/arc067/tasks/arc067_a

#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MOD = 1e9 +7 ;

vector<pair<long long, long long> > prime_fac( long long N ){
    vector<pair<long long, long long> > res;

    for(int i=2; i*i <=N; ++i){
        if( N % i ==0 ){
            long long ex = 0;
            while( N % i == 0 ){
                ex++;
                N /= i;
            }
            res.push_back({i, ex});
        }
    }

    if(N != 1){
        res.push_back({N, 1});
    }
    return res;
}

//can't calculate 1000!
// long long rec(long long N){
//     if(N == 0) return 1;
//     if(N == 1) return 1;

//     return N * rec(N-1);
// }

int main(){

    long long N;
    cin >> N;
    map<long long, long long> m;

    long long ans = 1;
    for(int i=1; i<=N; ++i){
        const auto &primes = prime_fac(i);
        for(auto p: primes){
            if(m.count(p.first) >0){
                m[p.first] += p.second;
            }else{
                m[p.first] = p.second;
            }
        }   
    }

    for(const auto& item : m){
        //+1 means chose zero
        ans *= (item.second+1);
        ans %= MOD;
    }

    cout << ans << endl;

}
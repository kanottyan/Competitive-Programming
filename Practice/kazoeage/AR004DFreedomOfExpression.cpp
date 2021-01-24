//https://atcoder.jp/contests/arc004/tasks/arc004_4
//https://qiita.com/drken/items/f2ea4b58b0d21621bd51#fn2

#include <vector>
#include <iostream>
#include <cmath> 

using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5+1;
long long fac[MAX], inv[MAX], finv[MAX]; 

vector<pair<long long, long long> > prime_fac(long long N){
    vector<pair<long long, long long> > res;
    for(int i=2; i * i <= N; ++i){
        if( N % i != 0) continue;
        long long ex = 0;
        while(N % i == 0){
            ex++;
            N /= i;
        }
        res.push_back({i, ex});
    }

    if(N != 1) res.push_back({N, 1});
    return res;
}

void COMinit(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] =1;
    for(int i=2; i<MAX; ++i){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i)%MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD)%MOD; 
}

int main(){
    long long N, M;

    cin >> N >> M;
    COMinit();

    const auto& res = prime_fac(abs(N));
    long long ans = 1;
    //the combination of numbers 
    for(auto prime_ex: res){
        ans *= COM( prime_ex.second + M -1, M - 1);
        ans %= MOD;
    }
    // the combination of signs
    long long sign_num = 0;
    if( N < 0 ){
        for(int i=0; i<=M; i=i+2 ){
            sign_num += COM(M, i);
            sign_num %= MOD;
        }

    }else{
        for( int i=1; i<=M; i=i+2){
            sign_num += COM(M, i);
            sign_num %= MOD;
        }
    }

    ans *= sign_num;
    ans %= MOD;

    cout << ans << endl;
}
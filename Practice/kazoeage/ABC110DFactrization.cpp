#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;
// const int MAX = 510000;
const int MAX = 10;


long long fac[MAX], finv[MAX], inv[MAX];

vector<pair<long long, long long> > prime_factorization(long long N){
    vector<pair<long long, long long> > res;
    for(long long i=2; i*i <= N; ++i){
        if(N % i != 0)continue;
        long long ex = 0;

        while( N%i == 0){
            ex++;
            N /= i;
        }
        res.push_back({i, ex});
    }
    if(N != 1){
        res.push_back({N,1});
    }
    
    return res;
}

// //テーブルを作る前処理
void COMinit(){
    fac[0]  = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for(int i=2; i < MAX; ++i){
        fac[i] = fac[i-1] * i %MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

// //二項係数
long long COM(int n, int k){
    if( n < k) return 0;
    if(n<0 || k < 0)return 0;
    return fac[n] * (finv[k] * finv[n-k] %MOD) %MOD;
}

int main(){
    long long N, M;
    cin >> N >> M;
    COMinit();

    const auto& res = prime_factorization(M);
    long long ans = 1;
    for(auto prime_ex: res){
        ans *= COM( prime_ex.second+N-1, N-1);
        ans %= MOD;
    }

    cout << ans << endl;
}
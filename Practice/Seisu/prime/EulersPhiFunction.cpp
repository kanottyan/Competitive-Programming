//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=ja

//https://qiita.com/drken/items/a14e9af0ca2d857dad23#5-3-オイラー関数

#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long> > prime_fac(long long N){
    vector<pair<long long, long long> > res;

    for(long long i=2; i*i <= N; ++i){
        if( N%i != 0) continue;

        long long ex = 0;
        while( N%i == 0 ){
            ex++;
            N = N/i;
        }
        res.push_back({i, ex});
    }

    if( N != 1){
        res.push_back({N, 1});
    }
    return res;
}

int main(){
    long long n;
    cin >> n;

    const auto &primes = prime_fac(n);
    long long ans = n;
    for(auto p: primes){
        ans *= (p.first -1.0);
        ans /= p.first;
    }

    cout << ans << endl;
}
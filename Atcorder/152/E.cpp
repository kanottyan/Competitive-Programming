#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;
//const int MOD = 1000000007;

vector<pair<long long, long long>> prime_factorization(long long N){
    vector<pair<long long, long long>> res;

    for(long long i=2; i*i <= N; ++i){
        if( N%i != 0) continue;

        long long ex = 0;
        while(N%i == 0){
            N /= i;
            ex++;
        }
        res.emplace_back(i, ex);
    }

    if(N != 1) res.emplace_back(N, 1);
    return res;
}

int main(){
    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    map<long long, long long> mp;

    for(int i=0; i<N; ++i){
        auto res= prime_factorization(A[i]);
        for(auto pe : res){
            mp[pe.first] = max(mp[pe.first], pe.second);
        }
    }

    mint lcm_ans = 1;

    for(auto num_cnt : mp){
        mint num = num_cnt.first;
        mint cnt = num_cnt.second;

        for(int i=0; i<cnt.val(); ++i){
            lcm_ans *= num;
        }
    }

    mint ans = 0;
    for(int i=0; i<N; ++i){
        ans += lcm_ans/A[i];
    }

    cout << ans.val() << endl;

    return 0;
}
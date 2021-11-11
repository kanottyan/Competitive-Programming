#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint=modint1000000007;

int main(){
    int N; cin >> N;

    vector<mint> factor(N);
    for(int i=0; i<N; ++i){
        int n; cin >> n;
        factor[i] = n;
    }
    
    vector<mint> inverseN(N+1);
    inverseN[0] = 0;
    for(int i=1; i<=N; ++i){
        mint n = i;
        inverseN[i] += inverseN[i-1] + n.inv();
    } 

    vector<mint> dp(N);

    dp[0] = inverseN[N];

    // the probability the number will be added
    for(int i=1; i<N; ++i){
        mint a = N-i+1;
        mint b = 1+i;
        dp[i] = dp[i-1] - a.inv();
        dp[i] += b.inv();
    }

    vector<mint> exp(N);
    for(int i=0; i<N; ++i){
        exp[i] = factor[i] * dp[i];
    }

    mint sum = 0;
    for(int i=0; i<N; ++i){
        sum += exp[i];
    }

    mint tot = 1;
    for(int i=1; i<=N; ++i){
        tot *= i;
    }

    mint ans = tot * sum;
    cout << ans.val() << endl;

    return 0;
}
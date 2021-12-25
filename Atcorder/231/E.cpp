#include <bits/stdc++.h>
#include <atcoder/all>


#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)

using namespace std;
using namespace atcoder;

string to_n(){

}

long long dp[1000005][2];
int main() {
    int N;
    cin >> N;
    string X; cin >> X;

    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    long long mult = 1;
    if(N >= 2) mult = A[1]/A[0];

    dp[0][1] = 1;

    REP(i, (int)X.size()) {
        int now = (int)(X[i] - '0');
        dp[i + 1][0] = min(dp[i][0] + now, dp[i][1] + ( mult - now));
        dp[i + 1][1] = min(dp[i][0] + now + 1, dp[i][1] + ( mult - now - 1));
    }
    cout << dp[X.size()][0] << endl;
    return 0;
}
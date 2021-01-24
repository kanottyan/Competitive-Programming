//https://atcoder.jp/contests/practice2/tasks/practice2_f

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int MOD = 998244353;

int main(){
    int N, M;
    cin >> N >> M;

    vector<long long> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    vector<long long> b(M);
    for(int i=0; i<M; ++i) cin >> b[i];

    auto ans = convolution(a, b); 

    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << endl;
    }

}
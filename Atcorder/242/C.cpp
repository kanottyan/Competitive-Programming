#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main(){
    vector<mint> A(9, 1);
    int N; cin >> N;
    int cnt = 0;

    while(N>1){
        vector<mint> nA(9);
        nA[0] += A[0] + A[1];
        nA[8] += A[7] + A[8];
    
        for(int i=1; i<8; ++i){
            nA[i] += (A[i-1] + A[i] + A[i+1]);
        }
        swap(nA, A);
        N--;
    }

    mint ans = 0;
    for(int i=0; i<9; ++i){
        ans += A[i];
    }

    cout << ans.val() << endl;
    return 0;
}
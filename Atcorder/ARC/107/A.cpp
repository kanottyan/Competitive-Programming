#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;
const int MOD = 1e9+7;

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    
    mint sumA = ((1+A) * (A/2));
    if(A&1) sumA += (1+A)/2;

    mint sumB = ((1+B)*(B/2));
    if(B&1) sumB += (1+B)/2;

    mint sumC = ((1+C)*(C/2));
    if(C&1) sumC += (1+C)/2;

    mint res = sumA * sumB * sumC;

    cout << res.val() << endl;

}
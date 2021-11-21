#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main(){

    mint res = mint(15926535).pow(3*14);

    cout << res.val() << endl;

    return 0;
}
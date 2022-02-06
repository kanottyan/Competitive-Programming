#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


// check the cumsum, and the this would be the graph problem to see cumsum[0] and cumsum[N] is connected or not
int main(){

    int N, Q; cin >> N >> Q;
    dsu d(N+1);

    while(Q--){
        int l, r; cin >> l >> r;
        l--;

        d.merge(l, r);
    }

    if(d.same(0, N)) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
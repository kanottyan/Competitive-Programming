//https://atcoder.jp/contests/practice2/tasks/practice2_a

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, Q;
    cin >> N >>Q;

    dsu d(N);

    for(int qi=0; qi<Q; ++qi){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1){
            cout << d.same(u, v) << endl;
        }else{
            d.merge(u ,v);
        }
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    //0index なので自作のライブラリとidxが違うのに注意
    fenwick_tree<long long> BIT(N);
    for(int i=0; i<N; ++i) BIT.add(i, A[i]);

    for(int qi=0; qi<Q; ++qi){
        long long type; cin >> type;
        if(type == 0){
            int p, x; cin >> p >> x;
            BIT.add(p, x);
        }else{
            int l, r; cin >> l >> r;
            cout << BIT.sum(l, r) << endl;
        }
    }
}
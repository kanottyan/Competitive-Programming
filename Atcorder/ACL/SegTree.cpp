#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int op(int a, int b){
    return max(a, b);
}

int e(){
    return 0;
}

int main(){
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    segtree<int, op, e> seg(A);

    for(int qi=0; qi<N; ++qi){
        int type; cin >> type;

        if(type ==1){
            int X, T;
            cin >> X >> T;
            seg.set(X, T);
        }else if(type == 2){
            int L, R; cin >> L >> R;
            auto ans = seg.prod(L, R);
            cout << ans << endl;

        }else{
            int X, T;
            cin >> X >> T;
//            cout << seg.max_right(X, T) << endl;
        }
    }
}
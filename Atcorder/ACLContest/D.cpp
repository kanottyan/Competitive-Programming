#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int op(int a, int b){
    return max(a, b);
}

int e(){
    return (int)0;
}
const int MAX =300010;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    } 

    segtree<int, op, e> st(vector<int>(MAX, 0));
    for(int i=0; i<N; ++i){
        int l = max(0, A[i]-K);
        int r = min(MAX, A[i]+K+1);
        int h = st.prod(l, r);
        st.set(A[i], h+1);
    }

    int ans = st.all_prod();
    cout << ans << endl;
}

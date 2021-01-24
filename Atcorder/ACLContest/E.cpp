#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
const mint inv9 = mint(1)/9;

struct S{
    mint x; // -->その桁の値
    mint w; // -->桁の幅
    //初期化(単位元)10^0 = 1なのでw=1
    S(mint x=0, mint w=1): x(x), w(w){}
};

S op(S a, S b){
    return S(a.x*b.w+b.x, a.w*b.w);
}
//単位元
S e(){ return S();}

//写像の型
using F = int;

F ID(){
    return 0;
}

S mapping(F f, S x){
    if(f==ID()) return x;
    return S( (x.w-1)*inv9*f, x.w);
}

int composition(F f, F g){
    if(f == ID()) return g;
    return f;
}

int main(){
    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, F, mapping, composition, ID> seg(n);
    //各葉のSの初期化
    for(int i=0; i<n; ++i){
        seg.set(i, S(1,10));
    }

    for(int qi=0; qi < q; ++qi){
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        seg.apply(l, r, d);
        S ans = seg.all_prod();
        cout << ans.x.val() << endl;
    }
    return 0;
}

// struct S{
//     mint value;
//     int size;
// };

// using F = long long;
// F ID = 1 << 31; 


// S op(S a, S b){ return{ a.value+b.value, a.size+b.size }; }
// S e(){ return {0, 0};}
// S mapping(F f, S x){
//     if( f != ID ) x.value = x.size * f;
//     return x;
// }
// F composition(F f, F g){ 
//     if( f != ID ) return f;
//     else return g;
// }
// F id(){return ID;}



// int main(){
//     int n , q; 
//     cin >> n >> q;
//     lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<S>(n, {1, 1}));

//     for(int qi=0; qi < q; ++qi){
//         int l, r, d;
//         cin >> l >> r >> d;
//         l--; r--;
//         seg.apply(l, r+1, d);
//         cout << seg.all_prod().value.val() << endl;
//     }
// }
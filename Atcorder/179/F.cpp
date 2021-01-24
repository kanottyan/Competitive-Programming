#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;

const long long INF = 1LL << 60;

int main(){
    int n, q;
    cin >> n >> q;

    auto update = [](long long a, long long b) { return min(a, b); };
    auto e = [](){return INF;};
    //ACL ライブラリやと点更新方法がいじれない
    //    auto change = [](long long a, long long b) { return b; };
    segtree<long long, update, e> tx(n+1), ty(n+1);
    //点更新, 0-indexっぽい
    tx.set(n, n);
    ty.set(n, n);
    long long ans = (long long)(n-2) * (n-2);

    for(int qi=0; qi<q; ++qi){
        int typ, i;
        cin >> typ >> i;
        if(typ == 1){
            //区間取得[i,n+1)で動く
            //n+1は端っこまでの意味
            int r = tx.prod(i, n+1);
            ans -= r-2;
            //rをiで更新（前後を分けれる）
            ty.set(r, update(ty.get(r),i) );
        }else{
            int r = ty.prod(i, n+1);
            ans -= r-2;
            tx.set(r, update(tx.get(r),i) );            
        }
    }
    cout << ans << endl;
}   

// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1LL << 60;

// //https://tsutaj.hatenablog.com/entry/2017/03/30/224339
// //example of range add query
// class RMQLazySegmentTree{
// private:
//     int n;
//     vector<long long> node, lazy;
//     vector<bool> lazyFlag;
    
// public:
//     RMQLazySegmentTree(vector<long long> v){
//         int sz = (int)v.size();
//         n = 1; while(n < sz) n *= 2;
//         node.resize(2*n-1);
//         lazy.resize(2*n-1, INF);
//         lazyFlag.resize(2*n-1, false);

//         for(int i=0; i<sz; ++i){
//             node[i+n-1] = v[i];
//         }
//         for(int i=n-2; i>=0; --i){
//             node[i] = min(node[i*2+1], node[i*2+2]);
//         }
//     }


//     //kが現在の評価ノートの遅延伝播。lとrが指定範囲[l,r)
//     void lazyEvaluate(int k, int l, int r){
//         // 遅延配列が空でない場合、自ノード及び子ノードへの
//         // 値の伝播が起こる
//         if(lazyFlag[k]){
//             node[k] = lazy[k];
//             // 最下段かどうかのチェックをしよう
//             // 子ノードは親ノードの 1/2 の範囲であるため、
//             // 伝播させるときは半分にする
//             if(r - l > 1){
//                 lazy[2*k+1] = lazy[k];
//                 lazy[2*k+2] = lazy[k];
//                 lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
//             }

//             // 伝播が終わったので、自ノードの遅延配列を空にする
//             lazyFlag[k] = false;
//         }
//     }
    
//     //区間加算
//     // 区間[a,b)に関して、値をxに更新する
//     // x:更新する値、ノードk=[l,r)に着目している。
//     // [l,r)の初期値は全体
//     void update(int a, int b, long long x, int k=0, int l=0, int r = -1){
//         if(r < 0) r = n;
//         lazyEvaluate(k, l, r);
//         // 交差しない場合
//         if(r <= a || b <= l) return;

//         // a,l,r,bの順で完全に含まれる
//         if(a <= l && r <= b){
//             lazy[k] = x;
//             lazyFlag[k] = true;
//             lazyEvaluate(k, l, r);
//         }else{
//             update(a, b, x, 2*k+1, l, (l+r)/2);
//             update(a, b, x, 2*k+2, (l+r)/2, r);
//             node[k] = min(node[2*k+1], node[2*k+2]);
//         }
//     }

//    // 区間[a,b)
//     long long find(int a, int b, int k=0, int l=0, int r =-1){
//         if(r < 0) r=n;
//         //ノードが呼び出されたら評価
//         lazyEvaluate(k, l, r);

//         if(b <= l || r <= a) return INF;
//         if(a <= l && r <= b) return node[k];
//         long long vl = find(a, b, 2*k+1, l, (l+r)/2);
//         long long vr = find(a, b, 2*k+2, (l+r)/2, r);
//         return min(vl, vr);
//     }
// };

// int main(){
//     long long N, Q;
//     cin >> N >> Q;
//     vector<long long> col(N -2, N-2);
//     vector<long long> row(N-2, N-2);

//     RMQLazySegmentTree ColSegTree(col);
//     RMQLazySegmentTree RowSegTree(row);
//     long long black_tot = (N-2)*(N-2);


//     long long close_right_idx = N-2;
//     long long close_bottom_idx = N-2;

//     for(int _=0; _<Q; ++_){
//         int type, idx;
//         cin >> type >> idx;
//         idx--; idx--;

//         if(type == 1){
//             long long num = ColSegTree.find(idx, idx+1);
//             black_tot -= num;
//             ColSegTree.update(idx, idx+1, 0);
//             if( idx < close_right_idx ){
//                 close_right_idx = idx;
//                 RowSegTree.update(0, close_bottom_idx, idx);
//             }
//         }else{
//             long long num = RowSegTree.find(idx, idx+1);
//             black_tot -= num;
//             RowSegTree.update(idx, idx+1, 0);
//             if( idx < close_bottom_idx){
//                 close_bottom_idx = idx;
//                 ColSegTree.update(0, close_right_idx, idx);
//             }
//         }
//     }
//     cout << black_tot << endl;
// }
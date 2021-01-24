#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

//https://tsutaj.hatenablog.com/entry/2017/03/30/224339
//example of range add query
class RMQLazySegmentTree{
private:
    int n;
    vector<long long> node, lazy;
    vector<bool> lazyFlag;
    
public:
    RMQLazySegmentTree(vector<long long> v){
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);

        for(int i=0; i<sz; ++i){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; --i){
            node[i] = min(node[i*2+1], node[i*2+2]);
        }
    }


    //kが現在の評価ノートの遅延伝播。lとrが指定範囲[l,r)
    void lazyEvaluate(int k, int l, int r){
        // 遅延配列が空でない場合、自ノード及び子ノードへの
        // 値の伝播が起こる
        if(lazyFlag[k]){
            node[k] = lazy[k];
            // 最下段かどうかのチェックをしよう
            // 子ノードは親ノードの 1/2 の範囲であるため、
            // 伝播させるときは半分にする
            if(r - l > 1){
                lazy[2*k+1] = lazy[k];
                lazy[2*k+2] = lazy[k];
                lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
            }

            // 伝播が終わったので、自ノードの遅延配列を空にする
            lazyFlag[k] = false;
        }
    }
    
    //区間加算
    // 区間[a,b)に関して、値をxに更新する
    // x:更新する値、ノードk=[l,r)に着目している。
    // [l,r)の初期値は全体
    void update(int a, int b, long long x, int k=0, int l=0, int r = -1){
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        // 交差しない場合
        if(r <= a || b <= l) return;

        // a,l,r,bの順で完全に含まれる
        if(a <= l && r <= b){
            lazy[k] = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }else{
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

   // 区間[a,b)
    long long find(int a, int b, int k=0, int l=0, int r =-1){
        if(r < 0) r=n;
        //ノードが呼び出されたら評価
        lazyEvaluate(k, l, r);

        if(b <= l || r <= a) return INF;
        if(a <= l && r <= b) return node[k];
        long long vl = find(a, b, 2*k+1, l, (l+r)/2);
        long long vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
int main(){
    long long n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for(int i=0; i<n; ++i) a[i] = pow(2, 31) -1;
    //Segtree
    RMQLazySegmentTree SegTree(a);

    for(int _=0; _<q; ++_){
        int o;
        cin >> o;
        if(o){
            int s, t;
            cin >> s >> t;
            long long ans = SegTree.find(s,t+1);
            cout << ans << endl;
        }else{
            int s, t, x;
            cin >> s >> t >> x;
            SegTree.update(s, t+1, x);
        }
    }
}
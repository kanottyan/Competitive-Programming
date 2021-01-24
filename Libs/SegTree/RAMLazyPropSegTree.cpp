#include <bits/stdc++.h>
using namespace std;

//https://tsutaj.hatenablog.com/entry/2017/03/30/224339
//example of range add query
class RAQLazySegmentTree{
private:
    int n;
    vector<long long> node, lazy;
    
public:
    RAQLazySegmentTree(vector<long long> v){
        int sz = (int)v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; ++i){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; --i){
            node[i] = node[i*2+1] + node[i*2+2];
        }
    }


    //kが現在の評価ノートの遅延電波。lとrが指定範囲[l,r)
    void eval(int k, int l, int r){
        // 遅延配列が空でない場合、自ノード及び子ノードへの
        // 値の伝播が起こる
        if(lazy[k] != 0){
            node[k] += lazy[k];

            // 最下段かどうかのチェックをしよう
            // 子ノードは親ノードの 1/2 の範囲であるため、
            // 伝播させるときは半分にする
            if(r - l > 1){
                lazy[2*k+1] += lazy[k]/2;
                lazy[2*k+2] += lazy[k]/2;
            }

            // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }
    
    //区間加算
    // 区間[a,b)に関して、x:加える値ノードk=[l,r)に着目している。
    // [l,r)の初期値は全体
    void add(int a, int b, long long x, int k=0, int l=0, int r = -1){
        if(r < 0) r = n;
        eval(k, l, r);
        // 交差しない場合
        if(r <= a || b <= l) return;

        // a,l,r,bの順で完全に含まれる
        if(a <= l && r <= b){
            lazy[k] += (r-l) * x;
            eval(k, l, r);
        }else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
   // 区間[a,b)
    long long getsum(int a, int b, int k=0, int l=0, int r =-1){
        if(r < 0) r=n;
        //ノードが呼び出されたら評価
        eval(k, l, r);

        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        long long vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        long long vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};


// example question
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N, 0);
    RAQLazySegmentTree lst(a);

    for(int i=0; i<Q; ++i){
        int type; cin >> type;
        if(type == 0){
            //追加
            int s, t, x;
            cin >> s >> t >> x;
            lst.add(s-1, t, x);
        }else{
            int s, t;
            cin >> s >> t;
            //計算
            long long ans = lst.getsum(s-1, t);
            cout << ans << endl;
        }

    }
}
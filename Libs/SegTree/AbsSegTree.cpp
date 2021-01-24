#include <iostream>
using namespace std;

// //http://www.creativ.xyz/segment-tree-abstraction-979/

#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template <class T> class SegTree {
    int n;                          // 葉の数
    vector<T> data;                 // データを格納するvector
    T def;                          // 初期値かつ単位元
    function<T(T, T)> operation;    // 区間クエリで使う処理
    function<T(T, T)> update;       // 点更新で使う処理

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r){
        // 交差しない場合
        if(r <= a || b <= l) return def; 
        //// a,l,r,bの順で完全に含まれる
        if (a <= l && r <= b){
            return data[k]; 
        }else{
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }
    public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    //コンストラクタ
    SegTree(size_t _n, T _def, 
                    function<T(T, T)> _operation, 
                    function<T(T, T)> _update)
                    :def(_def), operation(_operation), update(_update){
        n=1;
        while(n < _n){
            n *= 2;
        }
        data = vector<T>(2*n -1, def);
    }

    //区間クエリ
    T query(int a, int b){
        return _query(a, b, 0, 0, n);
    }

    //更新クエリ:場所i(0-indexed)の値をxで更新
    void change(int i, T x){
        i += n -1;
        data[i] = update(data[i], x);
        while(i > 0){
            i = (i-1)/2;
            data[i] = operation(data[i*2+1], data[i*2+2]);
        }
    }

    // 添字でアクセス
    T operator[](int i){
        return data[i + n -1];
    }
};

//omake
int main(void) {
    int N, Q;
    cin >> N >> Q;
    // 要素数N・long long型・区間min・点更新
    SegTree<long long> st(N, (1LL << 31) - 1, [](long long a, long long b) { return min(a, b); },
                          [](long long a, long long b) { return b; });
    for(int j=0; j<Q; ++j){
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            // update(x, y)
            st.change(x, y);
        } else {
            // find(s, t)
            cout << st.query(x, y + 1) << endl;
        }
    }
 
    return 0;
}
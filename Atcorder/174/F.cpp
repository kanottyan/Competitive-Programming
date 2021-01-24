#include <bits/stdc++.h>
using namespace std;


//x の最も下の立っているビットは，x & -x で取り 出せる
template <class T> class BIT{
    public:
    vector<T> array;
    const int n;
    
    public:
    //constractor
    BIT(int _n) : array(_n + 1, 0), n(_n){}
    
    //sum [0,i]
    T sum(int i){
        T s = 0;
        while(i > 0){
            s += array[i];
            i -= i & -i;
        }
        return s;
    }

    //sum [i,j]
    T sum(int i, int j){
        T ret_i = sum(i -1);
        T ret_j = sum(j);
        return ret_j - ret_i;
    }

    // 1-index
    void add(int i, T x){
        while(i <= n){
            array[i] += x;
            i += i & -i;
        }
    }
};

// int main(){
//     int n, q;
//     cin >> n >> q;

//     vector<int> a(n);
//     for(int i=0; i<n; ++i) cin >> a[i];

//     //書く数について、最後に出てきた場所
//     vector<int> pi(n+1, -1);
//     //赤矢印の配列
//     vector<vector<int>> ps(n);
//     for(int i=0; i<n; ++i){
//         //a[i]が直前に出てきた場所
//         int l = pi[a[i]];
//         //赤い矢印に変換
//         if(l != -1) ps[l].push_back(i);
//         pi[a[i]] = i;
//     }

//     //青点(クエリ)のｎ番号と、その場所。
//     // lがx, rがy, qiがindex
//     vector<vector<pair<int, int>>> qs(n);

//     for(int qi=0; qi < q; ++qi){
//         int l, r;
//         cin >> l >> r;
//         --l, --r;
//         //青点に対応してる番号と座標
//         qs[l].emplace_back(r, qi);
//     }


//     BIT<int> bit(n);
//     vector<int> ans(q);

//     //大きい順にxを並べてやる
//     for(int x = n-1; x>=0; --x){
//         //赤点登録から先にやる
//         for(int y:ps[x]){
//             bit.add(y, 1);
//         }

//         //青点クエリの処理
//         for(pair<int, int> query: qs[x]){
//             int r = query.first;
//             int i = query.second;
//             //sumは重複分
//             ans[i] = (r-x+1) - bit.sum(r);
//         }
//     }

//     for(int i=0; i<q; ++i){
//         cout << ans[i] << endl;
//     }
// }


int N = 100;

int main(){
    int n, Q; cin >> n >> Q;
    BIT<int> bit(N);

    vector<int> a(N+1,0);
    vector<vector<int>> ql(N+1);
    vector<vector<int>> qid(N+1);
    vector<int> ans(N+1, 0);

    vector<int> C(N+1);
    for(int i=1; i<=n; ++i){
        cin >> C[i];
    }

    for(int i=1; i<=Q; ++i){
        int l, r;
        cin >> l >> r;
        ql[r].push_back(l);
        qid[r].push_back(i);
    }

    for(int i=1; i<=n; ++i){
        if(a[C[i]] > 0) bit.add(a[C[i]], -1);
        bit.add(i, +1);
        a[C[i]] = i;
        for(int j=0; j<ql[i].size(); ++j){
            ans[qid[i][j]] = bit.sum(ql[i][j], i);
        }
    }

    for(int i=1; i<=Q; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}


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

    //区間クエリ[a, b)
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


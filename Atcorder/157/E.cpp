#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

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

int main(){
    int N;
    cin >> N;

    vector<long long> alphabet_unit(26); 

    auto operate = [&](vector<long long> a, vector<long long> b){
        vector<long long> ans(26);
        for(int i=0; i<26; ++i){
            ans[i] = a[i] + b[i];
        }
        return ans;
    };

    auto update = [&](vector<long long> a, vector<long long> b){
        return b;
    };

    bool alphabet[26];

    // 要素数N・long long型・区間min・点更新
    SegTree< vector<long long> > st(N, alphabet_unit, operate, update);

    string s; cin >> s; 
    for(int i=0; i<s.size(); ++i){
        int idx = s[i] - 'a';
        vector<long long> alphabet(26);
        alphabet[idx] = 1;
        st.change(i, alphabet);
    }

    int Q; cin >> Q;
    for(int i=0; i<Q; ++i){
        int query_type; cin >> query_type;
        if(query_type == 1){
            int leave_id; cin >> leave_id;
            leave_id--;
            char c; cin >> c;
            vector<long long> alphabet(26);
            int idx = c - 'a';
            alphabet[idx] = 1;
            st.change( leave_id, alphabet);
        }else{
            int l, r; cin >> l >> r;
            l--;
            if(l ==r) r++;
            vector<long long> res = st.query(l, r);

            long long ans = 0;
            for(int i=0; i<26; ++i){
                if(res[i] > 0) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
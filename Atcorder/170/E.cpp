#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <functional>
#include <set>

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

// vector<multiset<long long> > y(10);
// vector<unordered_map<int, long long> > youtien(10);
// int infants_youchien[10];
// int infants_power[10];

vector<multiset<long long> > y(200010);
vector<unordered_map<int, long long> > youtien(200010);
int infants_youchien[200010];
int infants_power[200010];


bool compare_by_v(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

long long find_max_in_youchien(unordered_map<int, long long> youtien){
    // vector<pair<int, long long> > res(youtien.begin(), youtien.end());
    // sort(res.begin(), res.end(), compare_by_v);
    // return res[0].second;

    priority_queue<long long> q;
    for(auto kv: youtien){
        q.push(kv.second);
    }

    return q.top();
}

int main(){
    int N, Q;
    cin >> N >> Q;


    for(int i=1; i<=N; ++i){
        int a, b;
        cin >> a >> b;

        //i番目の幼児はb幼稚園にいる。
        infants_youchien[i] = b;
        //i番目の幼児のパワー
        infants_power[i] = a;

        //幼稚園にいれる
        youtien[b].insert({i, a});
        y[b].insert(a);
    }


    //最大の最小値を求める
    // 要素数N・long long型・区間min・点更新
    SegTree<long long> st(200010, (1LL << 31) - 1, [](long long a, long long b) { return min(a, b); },
                          [](long long a, long long b) { return b; });


    for(int i=1; i<200010; ++i){
        if(youtien[i].size() == 0) continue;
        long long mx = *prev(y[i].end());
        st.change(i-1, mx );
    }


    for(int i=0; i<Q; ++i){
        int c, d;
        cin >> c >> d;
        //幼児cを幼稚園dに移動
        //前の幼稚園
        int prev_youchien = infants_youchien[c];
        infants_youchien[c] = d;

        youtien[prev_youchien].erase(c);
        youtien[d].insert({c, infants_power[c]} );


        auto it = y[prev_youchien].find(infants_power[c]);
        y[prev_youchien].erase(it);
        y[d].insert(infants_power[c]);

        //もし取り除いて0になったらinf(1ll<<31)にする
        if( youtien[prev_youchien].size() > 0 ){
            st.change(prev_youchien -1, *prev(y[prev_youchien].end()));
        }else{
            st.change(prev_youchien -1, 1LL << 31);
        }

        st.change(d-1, *prev(y[d].end()));

        cout << st.query(0, 200010) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

const long long MINUS_INF = -1LL << 60;

struct UnionFind {
    vector<long long> par; // 親ノード
    vector<long long> rank; // ランク
    vector<long long> root_size; //ノードが根のときに、何個の子要素を持っているのか。(自分を含む)
                            //親じゃない場合は-1を出力

    UnionFind(long long n = 1) {
        init(n);
    }

    void init(long long n = 1) {
        par.resize(n); rank.resize(n); root_size.resize(n);
        for (long long i = 0; i < n; ++i) par[i] = i, rank[i] = 0, root_size[i] = 1;
    }

    long long root(long long x) {
        if (par[x] == x) {
            return x;
        }
        else {
            long long r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(long long x, long long y) {
        return root(x) == root(y);
    }

    //yをxにマージ
    bool merge(long long x, long long y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        root_size[x] += root_size[y];
        root_size[y] = -1;
        return true;
    }

    long long size(long long x){
        x = root(x);
        return root_size[x];
    }
};

int main(){
    int N; cin >> N;
    long long K; cin >> K;


    vector<long long> C(N+1);
    vector<long long> P(N+1);
    for(int i=1; i<=N; ++i){
        cin >> P[i];
    }

    for(int i=1; i<=N; ++i){
        cin >> C[i];
    }

    UnionFind uf = UnionFind(N+1);

    //cycle_root, cycle_point.
    map<int, long long> m;


    for(int i=1; i<=N; ++i){
        uf.merge(i, P[i]);
    }

    // rootを全更新
    for(int i=1; i<=N; ++i){
        uf.root(i);
        m[uf.root(i)] += C[P[i]];
    }

    long long ans = MINUS_INF;

    //最初に始める点
    for(int i=1; i<=N; ++i){

        //何回歩けるか
        long long rest_K = K;
        long long tmp_ans = 0;

        //サイクルが負なら一周のみ
        if(m[uf.root(i)] <= 0){
            long long cnt = min(rest_K, uf.root_size[uf.root(i)]);
            int t = P[i];
            for(int _=0; _< cnt; ++_){
                tmp_ans += C[t];
                ans = max(ans, tmp_ans);
                t = P[t];
            }
        }else{
        //正なら最後の一種になるまで動く
            long long cycle_size = uf.root_size[uf.root(i)];
            long long cycle_cnt = rest_K / cycle_size;
            long long rest = rest_K % cycle_size;
            //一周前から最大を見る
            cycle_cnt -= 1;

            tmp_ans = cycle_cnt * m[uf.root(i)];
            ans = max(ans, tmp_ans);
            rest_K -= cycle_cnt * cycle_size;

            int t = P[i];
            while(rest_K){
                tmp_ans += C[t];
                ans = max(ans, tmp_ans);
                t = P[t];
                rest_K--;
            }
        }
    }

    cout << ans << endl;
}
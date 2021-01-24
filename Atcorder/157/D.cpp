#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

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
    long long N;
    cin >> N;
    UnionFind UF(N);

    long long M; cin >> M;
    long long K; cin >> K;

    vector<long long> path_num(N);

    for(long long i=0; i<M; ++i){
        long long a, b; cin >> a >> b;
        a--; b--;
        path_num[a]++;
        path_num[b]++;
        UF.merge(a, b);    
    }

    for(long long i=0; i<N; ++i){
        UF.root(i);
    }

    vector<long long> node_edges(N);
    for(long long i=0; i<N; ++i){
        node_edges[i] = UF.size(i) -1;
    }

    //delete block
    for(long long i=0; i<K; ++i){
        long long c, d; cin >> c >> d;
        c--; d--;
        if(UF.issame(c, d)){
            path_num[c]++;
            path_num[d]++;
        }
    }

    for(long long i=0; i<N; ++i){
        cout << node_edges[i] - path_num[i] << endl;
    }

}
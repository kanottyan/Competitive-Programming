//question
//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja

#include <bits/stdc++.h>

using namespace std;

template<class Abel> struct UnionFind{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n=1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n=1, Abel SUM_UNITY = 0){
        par.resize(n); rank.resize(n), diff_weight.resize(n);
        for(int i=0; i<n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] ==x ){
            return x;
        }else{
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w){
        w += weight(x); w-= weight(y);
        x = root(x); y = root(y);
        if(x== y) return false;
        if(rank[x] < rank[y]) swap(x,y), w = -w;
        if(rank[x] == rank[y]) ++rank[x];

        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y){
        return weight(x) - weight(y);
    }

};

struct Edge{
    long long u;
    long long v;
    long long cost;

    Edge(long long u_, long long v_, long long c) : u(u_), v(v_), cost(c){};
};

// compare two edges cost 
bool comp_e(const Edge &e1, const Edge &e2){
    return e1.cost < e2.cost;
};

/*
    input: vector edge, node num V
    output: the sum of minimum spamming tree
    time complexity: O(|E|log|V|)
*/

struct Kruskal{
    UnionFind<int> uf;
    long long sum;
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_){
        init();
    }
    void init(){
        sort(edges.begin(), edges.end(), comp_e);
        uf = UnionFind<int>(V);
        sum = 0;
        for(auto e: edges){
            // if already same group, then do nothing
            if(uf.issame(e.u, e.v)) continue;
            uf.merge(e.u, e.v, 1);
            sum += e.cost;
        }
    }
};


int main(){
    int V, E; cin >> V >> E;
    vector<Edge> edges(E, Edge(0, 0, 0));
    for(int i=0; i<E; ++i){
        long long u, v, c; cin >> u >> v >> c;
        Edge e(u, v, c);
        edges[i] = e;
    }

    Kruskal krs(edges, V);
    cout << krs.sum << endl;
    return 0;
}
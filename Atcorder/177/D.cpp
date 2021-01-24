

#include <bits/stdc++.h>
using namespace std;

// ただのunion find が使いたいばあい
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
    int N, M;
    cin >> N >> M;
    UnionFind UF(N);

    for(int i=0; i<M; ++i){
        int A, B;
        cin >> A >> B;
        A--; B--;
        UF.merge(A, B);
    }

    for(int i=0; i<N; ++i){
        UF.root(i);
    }

    map<int, int> s;

    for(int i=0; i<N; ++i){
        if(s.count(UF.root(i)) == 0 ){
            s[UF.root(i)] = 1;
        }else{
            s[UF.root(i)]++;
        }
    }

    int res = 0;
    for(auto p : s){
        res = max(res, p.second);
    }


    cout << res << endl;

}

//ABC公式回答
// #include <bits/stdc++.h>
// #define rep(i,n) for (int i = 0; i < (n); ++i)
// using namespace std;
// using ll = long long;
// using P = pair<int,int>;

// // UnionFind
// // coding: https://youtu.be/TdR816rqc3s?t=726
// // comment: https://youtu.be/TdR816rqc3s?t=6822
// struct UnionFind {
//   vector<int> d;
//   UnionFind(int n=0): d(n,-1) {}
//   int find(int x) {
//     if (d[x] < 0) return x;
//     return d[x] = find(d[x]);
//   }
//   bool unite(int x, int y) {
//     x = find(x); y = find(y);
//     if (x == y) return false;
//     if (d[x] > d[y]) swap(x,y);
//     d[x] += d[y];
//     d[y] = x;
//     return true;
//   }
//   bool same(int x, int y) { return find(x) == find(y);}
//   int size(int x) { return -d[find(x)];}
// };

// int main() {
//   int n, m;
//   cin >> n >> m;
//   UnionFind uf(n);
//   rep(i,m) {
//     int a, b;
//     cin >> a >> b;
//     --a; --b;
//     uf.unite(a,b);
//   }

//   int ans = 0;
//   rep(i,n) ans = max(ans, uf.size(i));
//   cout << ans << endl;
//   return 0;
// }

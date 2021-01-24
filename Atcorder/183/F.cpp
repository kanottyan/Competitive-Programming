#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

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

    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    map<long long, map<long long, long long>> mp;
    for(int i=0; i<n; ++i){
        cin >> c[i], c[i]--;
        mp[i][c[i]] = 1;
    } 
    UnionFind uf(n);

    for(int qi=0; qi<q; ++qi){
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;


        if(type == 1){
            if(uf.issame(a, b)) continue;
            int parent_group = uf.root(a);
            int parent_group_b = uf.root(b);
            uf.merge(a, b);
            if(uf.root(a) != parent_group){
                swap(parent_group, parent_group_b);
            }
            
            for(auto elem : mp[parent_group_b]){
                if(!mp[parent_group].count(elem.first)){
                    mp[parent_group][elem.first] += elem.second;
                }else{
                    mp[parent_group][elem.first] += elem.second; 
                }
            }
        }else{
            int parent_group = uf.root(a);
            cout <<  mp[parent_group][b] << endl;
            
        }
    }

    return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

//ただのunion find が使いたいばあい
// struct UnionFind {
//     vector<long long> par; // 親ノード
//     vector<long long> rank; // ランク
//     vector<long long> root_size; //ノードが根のときに、何個の子要素を持っているのか。(自分を含む)
//                             //親じゃない場合は-1を出力

//     UnionFind(long long n = 1) {
//         init(n);
//     }

//     void init(long long n = 1) {
//         par.resize(n); rank.resize(n); root_size.resize(n);
//         for (long long i = 0; i < n; ++i) par[i] = i, rank[i] = 0, root_size[i] = 1;
//     }

//     long long root(long long x) {
//         if (par[x] == x) {
//             return x;
//         }
//         else {
//             long long r = root(par[x]);
//             return par[x] = r;
//         }
//     }

//     bool issame(long long x, long long y) {
//         return root(x) == root(y);
//     }

//     //yをxにマージ
//     bool merge(long long x, long long y) {
//         x = root(x); y = root(y);
//         if (x == y) return false;
//         if (rank[x] < rank[y]) swap(x, y);
//         if (rank[x] == rank[y]) ++rank[x];
//         par[y] = x;
//         root_size[x] += root_size[y];
//         root_size[y] = -1;
//         return true;
//     }

//     long long size(long long x){
//         x = root(x);
//         return root_size[x];
//     }
// };


// vector<string> split_native(const string &s, char delim) {
//     vector<string> elems;
//     string item;
//     for (char ch: s) {
//         if (ch == delim) {
//             if (!item.empty())
//                 elems.push_back(item);
//             item.clear();
//         }
//         else {
//             item += ch;
//         }
//     }
//     if (!item.empty())
//         elems.push_back(item);
//     return elems;
// }

int main(){
    int N;

    while(cin >> N){
        if(N ==0) break;

        UnionFind<int> UF(200);
        map<string, int> m;
        int idx = 0;
        bool flag = true;

        for(int i=0; i<N; ++i){
            string one, unit1, equal, val, unit2;
            cin >> one >> unit1 >> equal >> val >> unit2;
            if(m.count(unit1) == 0){
                m[unit1] = idx;
                ++idx;
            }
            int id1 = m[unit1];

            if(m.count(unit2) == 0){
                m[unit2] = idx;
                ++idx;
            }
            int id2 = m[unit2]; 

            // int w;
            // vector<string> vec;
            // vec = split_native(val, '^');
            // w = stoi(vec[1]);

            // 単位換算の倍率の取得
            stringstream si(val.substr(3));
            int w;
            si >> w; // "1 kilometre = 10^3 metre" の 3 の部分を取得


            if(UF.issame(id1, id2)){
                int diff = UF.diff(id1, id2);
                if(diff != w) flag = false;
            }else{
                UF.merge(id1, id2, w);
            }                 
        }
        if(flag){
            puts("Yes");
        }else{
            puts("No");
        }
    }    
}
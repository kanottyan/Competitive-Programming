//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
//https://scrapbox.io/pocala-kyopro/強連結成分分解

// StronglyConnectedComponents(g):= グラフ gで初期化する。
// build(t):= 強連結成分分解をする。強連結成分の番号はトポロジカル順に昇順にふられる。 tには強連結成分ごとに縮約したグラフが格納される(多重辺が生えるので注意)。
// [k] := 頂点 kが属する強連結成分の番号を返す。
//scc[i]で頂点iが何番目の成分に含まれているかが分かる。

#include <bits/stdc++.h>
using namespace std;

using G = vector<vector<int>>;

struct StronglyConnectedComponents {
  const G &g;
  G gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(G &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};


int main() {
  int V, E, Q;
  scanf("%d %d", &V, &E);
  G g(V), buff;
  for(int i = 0; i < E; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
  }
  StronglyConnectedComponents< G > scc(g);
  scc.build(buff);
  scanf("%d", &Q);
  while(Q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    puts(scc[a] == scc[b] ? "1" : "0");
  }
}

// template<class G> class StronglyConnectedCompoents {
//     const G &g;
//     UnweightedGraph ng, rg; // normal-graphとreversed-graph
//     vector<int> compo, order, visited;  // compo…頂点がどの成分に属しているか、order…帰りがけ順で何番目か

//     StronglyConnectedCompoents( G &g) : g(g), 
//         ng(g.size()), 
//         rg(g.size())),
//         compo(g.size() -1), 
//         visited(g.size())
//     {
//         for(int i=0; i<g.size(); i++){
//             for(auto t: g[i]){
//                 ng[i].emplace_back((int)t);
//                 rg[(int)t].emplace_back(i); //逆辺
//             }
//         }
//     }

//     // [] で聞かれたときに成分番号を返す
//     int operator[](int k){
//         return compo[k];
//     }

//     void dfs(int cur_node){
//         if(visited[cur_node]) return;
//         visited[cur_node] = true;

//         for(auto next_node : ng[cur_node]) dfs(next_node);
//         //帰りかけで記録
//         order.emplace_back(cur_node);
//     }

//     void rdfs(int cur_node, int count){
//         //used代わりに結果を入れる
//         if(compo[cur_node] != -1)return;
//         compo[cur_node] = count;
//         for(auto next_node : rg[cur_node]) rdfs(next_node, count);
//     }

//     void build(UnweightedGraph &ret){
//         for(int i=0; i<gg.size(); ++i) dgs(i);
//         reverse(order.begin(), order.end());
//         int ptr = 0;
//         for(int i: order){
//             if(comp[i] == -1){
//                 rdfs(i, ptr); 
//                 ptr++;
//             } 
//         }
//         t.reseize(ptr);
//         for(int i=0; i<g.size(); ++i){
//             for(auto &to : g[i]){
//                 int x = comp[i], y = comp[to];
//                 if(x == y) continue;
//                 t[x].push_back(y);
//             }
//         }
//     };
// };


#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M, Q; cin >> N >> M >> Q;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    //array [weight, is_original_edge,from, to, question_idx(original edge will be -1) ]
    vector<vector<int>> edges(M);
    for(int i=0; i<M; ++i){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges[i] = {c, 1,a,b, -1};
        pq.push(edges[i]);
    }

    vector<vector<int>> qedges(Q);
    for(int i=0; i<Q; ++i){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        qedges[i] = {w, 0, u, v, i};
        pq.push(qedges[i]);
    }

    dsu d(N);
    vector<bool> ans(Q);

    while(!pq.empty()){
        bool is_original = pq.top()[1];
        int from = pq.top()[2];
        int to = pq.top()[3];
        int qidx = pq.top()[4];
        pq.pop();

        if(from == to) continue;

        if(is_original){
            d.merge(from, to);
        }else{
            if(!d.same(from, to)) ans[qidx] = true;
        }
    }

    for(int i=0; i<Q; ++i){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
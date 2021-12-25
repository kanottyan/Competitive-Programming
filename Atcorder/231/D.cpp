#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int arr[100010];

bool flag = true;
vector<vector<int>> g;
vector<bool> seen, finished;

void dfs(int v, int p){
    seen[v] = true;
    for(int nv: g[v]){
        if(nv == p) continue;
        if(finished[nv]) continue;
        if(seen[nv] && !finished[nv]){
            flag = false;
            return;
        }
        dfs(nv, v);

        if(!flag) return;
    }
    finished[v] = true;
}

int main(){
    int N, M; cin >> N >> M;
    seen.assign(N, false), finished.assign(N, false);
    g.resize(N);
    set<pair<int, int>> s;
    dsu d(N);

    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        if(s.count(make_pair(a, b))) continue;
        s.insert(make_pair(a, b));
        d.merge(a, b);

        g[a].push_back(b);
        g[b].push_back(a);
        if(g[a].size() > 2){
            flag = false;
        }
        if(g[b].size() > 2){
            flag = false;
        }
    }

    //dfs
    vector<vector<int>> groups = d.groups();
    for(int i=0; i<groups.size(); ++i){
        dfs(groups[i][0], -1);
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}

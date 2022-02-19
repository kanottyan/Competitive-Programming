#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<vector<int>> g;
vector<vector<int>> n_array;
vector<int> X;

void merge(int id, vector<int> p, vector<int> c){
    int i=0;
    int j=0;
    int idx = 0;

    int a = p.size()+c.size();

    int num = min(20, a);

    vector<int> newarray(num);

    while(num--){
        if( p.size() == 0 || i > p.size()-1 ){
            newarray[idx] = c[j];
            j++;
        }else if( c.size() == 0 || j > c.size()-1){
            newarray[idx] = p[i];
            i++;
        }else{
            if(p[i] >= c[j] ){
                newarray[idx] = p[i];
                i++;
            }else{
                newarray[idx] = c[j];
                j++;
            }
        }
        idx++;
    }
    n_array[id] = newarray;
}


void rec(int node, int parent){
    //is leaves
    if(g[node].size()==1 && g[node][0] == parent){
        return ;
    }

    for(int child : g[node]){
        if(child == parent) continue;
        if(n_array[child].size() == 1 ) rec(child, node);
        merge(node, n_array[node], n_array[child]);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    X.resize(N);
    g.resize(N);
    n_array.resize(N);

    for(int i=0; i<N; ++i) cin >> X[i];
    for(int i=0; i<N; ++i) n_array[i].push_back(X[i]);
    

    for(int i=0; i<N-1; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //init
    rec(0, -1);

    while(Q--){
        int v, k; cin >> v >> k; v--; k--;
        cout << n_array[v][k] << endl;
    }
}
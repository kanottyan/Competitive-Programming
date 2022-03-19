#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

struct Prim {
    const int INF = 1e9;
    int sum; // MST weight sum
    set<pair<int, int>> edges; //nodes connected
    int V;  // nodes num
    vector<vector<int>> G; //graph
    vector<bool> confirmed; // fixe the node or not.
    vector<int> weight; //each node weight from a node
    
    // only required if you use Dijkstra
    // generated as array, idx:0 is weight, idx:1 is the node number
    priority_queue< vector<long long>, 
                    vector<vector<long long > >, 
                    greater<vector<long long > > > que;

    Prim(vector<vector<int>> const& graph): G(graph)
    {
        init();
    }

    void init(){
        this->V = G.size();
        this->sum = 0;
        this->weight.assign(V, INF);
        this->confirmed.assign(V, false);
        this->edges = set<pair<int, int>>();
    };

    void primByDijkstra(){
        //O: O(|E|log|V|) as using heap can make |V| as log
        // start from first node
        int begin = 0; 
        weight[begin] = 0;
        que.push({weight[begin], begin, -1});
        while(!que.empty()){
            vector<long long> cur_node_info = que.top();
            int cur_node = cur_node_info[1];
            int cur_node_w = cur_node_info[0];
            int from = cur_node_info[2];
            que.pop();

            if(cur_node_w < weight[cur_node_w]){
                weight[cur_node_w] = cur_node_w;
            }

            confirmed[cur_node] = true;
            sum += cur_node_w;
            if(from != -1){
                edges.insert({from, cur_node});
            }

            for(int next_node=0; next_node<V; ++next_node){
                if(G[cur_node][next_node] == -1) continue;
                que.push({ G[cur_node][next_node]+cur_node_w, next_node, cur_node });                
            }
        }
    }

    void primByForLoop(){
        //O: o(|V|^2) as we do for loop to get the minimum number every time
        //suppose we start from node 0
        weight[0] = 0;
        while (true){
            int next_candidate = -1;
            // find the node can go with minumum wight from confirmed nodes
            for(int u =0; u<V; ++u){
                if(confirmed[u]) continue;
                if((next_candidate == -1 || weight[u] < weight[next_candidate])){
                    next_candidate = u;
                }
            }
            if(next_candidate == -1){
                //if no more node can go, then it means MST is done
                break;
            }
            confirmed[next_candidate] = true;
            sum += weight[next_candidate];
            // once fixed the node, then update the weight can go from confirmed nodes
            for(int u=0; u < V; ++u){
                if(G[next_candidate][u] == -1) continue;
                weight[u] = min(weight[u], G[next_candidate][u]);
            }
        }
    }
};

int main(){
    int N, M; cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(N, -1));
    for(int i=0; i<M; ++i){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }


    Prim prim(G);

    prim.primByDijkstra();
    cout << "test" << endl;


    return 0;
}
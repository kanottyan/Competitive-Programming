#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

//how many subset does the node have
vector<long long> dp(200100, -1);
vector<vector<int>> G;
vector<long long> score(200100, -1);
// the answer when currently we focus on 0
long long sum = 0;
int N; 

int init_subset_and_dist(int v, int p = -1, int depth =0){

    if(dp[v] != -1 ) return dp[v];
    //init the dist
    dp[v] = 0;
    sum += depth;
    
    for(int next_node : G[v]){
        if(next_node == p) continue;
        dp[v] += init_subset_and_dist(next_node, v, depth+1) +1;
    }    
    return dp[v];
}

void dfs(int v, int p = -1){
    if(p == -1){
        score[v] = sum;
    }else{
        long long p_score = score[p];        
        long long subset = dp[v] + 1;
        long long non_subset = N - subset;
        score[v] = p_score - subset + non_subset;
    }
    
    for(int next_node : G[v]){
        if(next_node == p) continue;
        dfs(next_node, v);
    }   
}

int main(){

    cin >> N;
    G.resize(N);

    for(int i=0; i<N-1; ++i){
        int u, v;  cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    init_subset_and_dist(0);
    dfs(0);

    for(int i=0; i<N; ++i){
        cout << score[i] << endl;
    }

    return 0;
}
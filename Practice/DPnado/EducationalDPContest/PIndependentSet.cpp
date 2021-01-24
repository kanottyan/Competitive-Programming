#include <vector>
#include <iostream>

using namespace std;

//dp[i][j]=(頂点iを(j = 1黒く: j = 0白く)塗ったとき、iを親とする部分木の塗り方の場合の数)
long long dp[100100][2];
//long long dp[100][2];

vector<vector<int>> g;
const int MOD = 1e9 + 7;

void dfs(int v, int p){
    dp[v][0] = 1;
    dp[v][1] = 1;

    for(auto next_n : g[v]){
        if(next_n == p) continue;
        dfs(next_n, v);
        //自分が白なら白黒どっちでもok
        dp[v][0] = dp[v][0] * (dp[next_n][0] + dp[next_n][1]);
        dp[v][0] %= MOD;
        //黒ならその前は絶対に白
        dp[v][1] = dp[v][1] * dp[next_n][0];
        dp[v][1] %= MOD;
    }
}

int main(){
    int N;
    cin >> N;

    g.resize(N);

    for(int i=0; i<N-1; ++i){
        int x, y;
        cin >>x >> y;
        --x; --y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1])%MOD << endl;
}
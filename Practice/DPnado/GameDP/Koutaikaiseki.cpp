//https://qiita.com/drken/items/4e1bcf8413af16cb62da#例題-3-edpc-l-問題---deque-得点差も最大化したい-
//https://atcoder.jp/contests/arc038/tasks/arc038_d

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// グラフの頂点数、辺数、各ノードの重み
int N, M;
vector<int> X;

// game graph(後退解析のために辺の向きを逆にする)
vector<vector<int> > G;
vector<int> deg; // ゲームグラフにおける出次数 (辺の向きを逆にした状態で入次数)

// 二分探索判定 (D 以上にできるかどうか)
bool judge(int D){
    vector<int> cdeg = deg;
    queue<int> que;// キュー
    vector<int> dp(N*2, -1); // 最初は全体を -1 で初期化

    //初期条件
    for(int i=0; i<N; ++i){
        if(X[i] >= D){
            //値 Xv が D 以上で先手番: そのまま「先手勝ち」で dp[v]=1 です
            dp[i] = 1; // 先手勝ち
            que.push(i);
            //値 Xv が D 以上で後手番で deg[v]=0: 「後手負け」で dp[v]=0 です
            if(cdeg[i] == 0){
                dp[i+N] = 0; // 後手負け
                que.push(i+N);
            }
        }else{
            //値 Xv が D 未満で後手番: そのまま「後手勝ち」で dp[v]=1 です
            dp[i+N] =1;// 後手勝ち
            que.push(i+N);
            //値 Xv が D 未満で先手番で deg[v]=0: 「先手負け」で dp[v]=0 です
            if(cdeg[i] == 0){
                dp[i] = 0; // 先手負け
                que.push(i);
            }
        }
    }

    // 後退解析
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto nv: G[v]){
            //すでに見た頂点はスルー
            if(dp[nv] != -1) continue;

            --cdeg[nv];  // 辺 (nv, v) を削除
            if(dp[v] == 0){
                dp[nv] =1;
                que.push(nv);
            }
            else if(dp[v] == 1){
                if(cdeg[nv] == 0){
                    dp[nv] = 0;
                    que.push(nv);
                }
            }
        }
    } 
    // ノード 0 が先手番で勝ちかどうか
    return (dp[0] == 1);
}


int main(){
    //input
    cin >> N >> M;
    //先手がノード i (i=0,1,…,N−1) にいる状態: i
    //後手がノード i (i=0,1,…,N−1) にいる状態: i+N
    X.resize(N*2);

    for(int i=0; i<N; ++i){
        cin >> X[i];
    }

    for(int i=0; i<N; ++i){
        X[i+N] = X[i];
    }
    G.assign(N*2, vector<int>());
    deg.assign(N*2, 0);

    for(int i=0; i<M; ++i){
        int a,b; cin >> a >> b;
        --a; --b;
        G[b+N].push_back(a); // 後手番での後退遷移
        G[b].push_back(a+N); // 先手番での後退遷移
        deg[a]++; deg[a+N]++;
    }

    //binary search
    int low = 0, high = 10;// low: 絶対先手勝つ、high: 絶対先手負ける
    while(high - low >1){
        int mid = (low + high) /2;
        if(!judge(mid)) high = mid;
        else low = mid;
    }

    cout << low << endl;
}
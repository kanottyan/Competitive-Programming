#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, };
const int dy[4] = { 0, 1, };

vector<string> field;
vector<vector<int>> dp;


int main(){
    int H, W; cin >> H >> W;
    field.resize(H);
    dp.assign(H, vector<int>(W,-1));
    dp[0][0] = 1;

    for(int h=0; h<H; ++h){
        cin >> field[h];
    }    

    queue<pair<int, int>> que;
    que.push(make_pair(0, 0)); // スタートを push


    while(!que.empty()){
        pair<int, int> current_pos = que.front(); // キューの先頭を見る (C++ ではこれをしても pop しない)
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop(); // キューから pop を忘れずに

        for (int direction = 0; direction < 2; ++direction) {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue; // 場外アウトならダメ
            if (field[next_x][next_y] == '#') continue; // 壁はダメ

            // まだ見ていない頂点なら push
            if (dp[next_x][next_y] < dp[x][y]+1 ) {
                que.push(make_pair(next_x, next_y));
                dp[next_x][next_y] = dp[x][y] + 1; // (next_x, next_y) の距離も更新
                // prev_x[next_x][next_y] = x;  // どの頂点から情報が伝播して来たか、縦方向の座標をメモ
                // prev_y[next_x][next_y] = y;  // どの頂点から情報が伝播して来たか、横方向の座標をメモ
            }
        }
    }

    int ans = 0;
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            ans = max(ans, dp[h][w]);
        }
    }

    cout << ans << endl;
    return 0;
}
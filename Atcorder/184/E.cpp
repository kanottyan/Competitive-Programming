#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

const long long INF = __LONG_LONG_MAX__;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    for(int i=0; i<H; ++i){
        cin >> field[i];
    }

    /* スタート地点とゴール地点 */
    int sx, sy, gx, gy;
    //テレポート記録
    map<char, vector<pair<int, int>>> mv; 

    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if(field[h][w] == '.') continue;
            if(field[h][w] == '#') continue;
            if (field[h][w] == 'S') {
                sx = h;
                sy = w;
            }else if (field[h][w] == 'G') {
                gx = h;
                gy = w;
            }else{
                //文字の場合
                char alpha = field[h][w];
                mv[alpha].push_back({h, w}); 
            }
        }
    }

    vector<vector<long long> > dist(H, vector<long long>(W, INF)); 
    dist[sx][sy] = 0; // スタートを 0 に

    // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
    queue<pair<int, int>> que;
    que.push({sx, sy});

    // queue<pair<int, int>> que; 
    // queue.push(make_pair(sx, sy)); // スタートを push

    set<char> done_warp;
    while (!que.empty()) {
        pair<int, int> current_pos = que.front(); // キューの先頭を見る
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop(); // キューから pop を忘れずに

        if( isalpha(field[x][y]) && islower(field[x][y]) && done_warp.count(field[x][y]) == 0 )
        {
            //次の一手がワープの場合
            char alpha = field[x][y];
            done_warp.insert(alpha);
            for(auto p : mv[alpha]){
                int next_x = p.first;
                int next_y = p.second;
                // まだ見ていない頂点なら push
                if ( dist[x][y] + 1 < dist[next_x][next_y] ) {
                    que.push(make_pair(next_x, next_y));
                    dist[next_x][next_y] = dist[x][y] + 1;
                }
            }
        }
        //今の点が.の場合
        // 隣接頂点を探索
        for (int direction = 0; direction < 4; ++direction) {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue; // 場外アウトならダメ
            if (field[next_x][next_y] == '#') continue; // 壁はダメ

            // まだ見ていない頂点なら push
            if ( dist[x][y] + 1 < dist[next_x][next_y]) {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }

    if(dist[gx][gy] == INF){
        cout << -1 << endl;
    }else{
        cout << dist[gx][gy] << endl;
    }
    return 0;
}

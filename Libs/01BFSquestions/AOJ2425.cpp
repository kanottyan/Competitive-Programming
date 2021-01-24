//https://onlinejudge.u-aizu.ac.jp/problems/2425
//https://misteer.hatenablog.com/entry/AOJ-2425

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

const int INF = 1 << 30;

const int dx[7] = {0, 1, 1, 0, -1, -1, 0};
const int dy[2][7] = {{1, 0, -1, -1, -1, 0, 0}, {1, 1, 0, -1, 0, 1,0}};

int main(){
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    int N;
    cin >> N;
    vector<int> ox(N), oy(N);

    for(int i=0; i<N; ++i){
        cin >> ox[i] >> oy[i];
    }

    int lx, ly;
    cin >> lx >> ly;

    //全体をlx, lyずらして非負整数座標にする
    sx += lx; sy += ly, gx += lx, gy += ly;

    int H = lx * 2, W = ly * 2;
    vector<vector<bool>> obj(H + 1, vector<bool>(W + 1, false));
    for(int i=0; i<N; ++i){
        obj[ox[i] + lx][oy[i] + ly] = true;
    }

    //指示に逆らった回数を時刻
    vector<vector<vector<int>>> dist(H +1, vector<vector<int>>(W + 1, vector<int> (6, INF)));
    dist[sx][sy][0] = 0;

    deque<tuple<int, int, int, int>> que;
    //x座標, y座標, 経過時間t, 移動コストt
    que.emplace_back(sx, sy, 0, 0);

    while(!que.empty()){
        int x, y, t, d;
        tie(x, y, t, d) = que.front();
        que.pop_front();

        //距離が今よりも長かったら何もしない
        if(d > dist[x][y][t]) continue;

        int dir = abs((x - lx) * (y - ly) * t)%6; //お姉さんの指示
        int nt = (t + 1) % 6;

        for(int i=0; i < 7; ++i){
            int nx = x + dx[i];
            int ny = y + dy[abs(x - lx)%2][i];

            //座標が最大、最小を超えた場合、障害物がある場合、次に進んだ時にもうすでに試した方法よりも時間
            //がかかる場合は考慮しない
            if(nx < 0 || H < nx || ny < 0 || W < ny || obj[nx][ny] || 
            dist[nx][ny][nt] <= dist[x][y][t] + (i != dir)) continue;

            if(i == dir){
                //指示に従うなら距離増えない
                dist[nx][ny][nt] = dist[x][y][t];
                que.emplace_front(nx, ny, nt, dist[nx][ny][nt]);
            }else{
                dist[nx][ny][nt] = dist[x][y][t] + 1;
                que.emplace_back(nx, ny, nt, dist[nx][ny][nt]);
            }
        }
    }

    int ans = INF;
    for(int t=0; t < 6; ++t){
        ans = min(ans, dist[gx][gy][t]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
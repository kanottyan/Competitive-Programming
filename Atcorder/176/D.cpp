#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){

    long long H, W;
    cin >> H >> W;

    //scores, init as INF 
    vector<vector<long long>> score(H, vector<long long>(W, INF));

    int CH, CW; cin >> CH >> CW; CH--; CW--;
    int DH, DW; cin >> DH >> DW; DH--; DW--;

    vector<string> S(H);
    for(int h=0; h<H; ++h){
        cin >> S[h];
    }

    //x, y, cost
    deque<tuple<int, int, int>> que;
    que.emplace_back(CH, CW, 0);
    score[CH][CW] = 0;

    while(!que.empty()){
        int h, w, c;
        tie(h, w, c) = que.front();
        que.pop_front();

        if(c > score[h][w]) continue;

        //普通の移動
        for(int dir=0; dir<4; ++dir){
            int nh = h + dy[dir];
            int nw = w + dx[dir];

            if( nw < 0 || W <= nw || nh < 0 || H <= nh || S[nh][nw] == '#'  ){
                continue;
            }

            int nc = c;
            if(nc < score[nh][nw]){
                score[nh][nw] = nc;
                que.emplace_front(nh, nw, nc);
            }
        }
        
        //魔法
        for(int dh=-2; dh<=2; ++dh){
            for(int dw=-2; dw<=2; ++dw){
                int nh = h + dh;
                int nw = w + dw;
                if( nw < 0 || W <= nw || nh < 0 || H <= nh || S[nh][nw] == '#'  ){
                    continue;
                }
                int nc = c+1;
                if(nc < score[nh][nw]){
                    score[nh][nw] = nc;
                    que.emplace_back(nh, nw, nc);
                }
            }
        }
    }

    if(score[DH][DW] == INF){
        cout << -1 << endl;
    }else{
        cout << score[DH][DW] << endl;
    }
}


// bool foot_visited[1010][1010];
// bool magic_visited[1010][1010];
// //枝刈り用
// bool magictriedfrom[1010][1010];
// bool magictriedto[1010][1010];

// // bool foot_visited[10][10];
// // bool magic_visited[10][10];
// long long magic[1010][1010];
// // long long magic[10][10];

// vector<string> field;

// int H, W;

// // 四方向への移動ベクトル
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// int main(){
//     cin >> H >> W;
//     int CH, CW; cin >> CH >> CW;
//     CH--; CW--;
//     int DH, DW; cin >> DH >> DW;
//     DH--; DW--;

//     //init
//     for(int i=0; i<H; ++i){
//         for(int j=0; j<W; ++j){
//             magic[i][j] = INF;
//         }
//     }

//     field.resize(H);
//     for(int h=0; h<H; ++h) cin >> field[h];

//     int magic_cnt = 0;

//     //BFS
//     queue<pair<pair<int, int>, long long>> foot_que;
//     queue<pair<pair<int, int>, long long>> magic_que;

//     magic[CH][CW] = 0;

//     foot_que.push({{CH, CW}, 0});

//     while(!foot_que.empty() || !magic_que.empty()){
//         while(!foot_que.empty()){
//             int h = foot_que.front().first.first;
//             int w = foot_que.front().first.second;
//             long long cnt = foot_que.front().second;
//             magic[h][w] = min(magic[h][w], cnt);

//             foot_visited[h][w] = true;
//             foot_que.pop();
//             //歩く場合
//             for (int dir = 0; dir < 4; ++dir) {
//                 int nh = h + dx[dir];
//                 int nw = w + dy[dir];

//                 // 移動先が探索済みの場合
//                 if (foot_visited[nh][nw]) continue;

//                 // 場外アウトしたり、移動先が壁の場合はスルー
//                 if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

//                 //枝刈りも行う
//                 if (field[nh][nw] == '#' && magictriedfrom[h][w] == false){
//                     magictriedfrom[h][w] = true;
//                     magic_que.push({{h, w}, cnt});
//                 }

//                 if( field[nh][nw] == '#' ) continue;
//                 foot_que.push({{nh, nw}, cnt});
//             }
//         }

//         while(!magic_que.empty()){
//             int h = magic_que.front().first.first;
//             int w = magic_que.front().first.second;
//             long long cnt = magic_que.front().second;
//             magic[h][w] = min(magic[h][w], cnt);

//             magic_visited[h][w] = true;
//             magic_que.pop();
//             //魔法の場合
//             for(int dx = -2; dx <= 2; ++dx){
//                 for(int dy = -2; dy <= 2; ++dy){
//                     magic_visited[h][w] = true;
//                     int mnh = h + dx;
//                     int mnw = w + dy;
//                     long long new_cnt = cnt +1;

//                     // 場外アウトしたり、移動先が壁の場合はスルー
//                     if (mnh < 0 || mnh >= H || mnw < 0 || mnw >= W) continue;
//                     if (field[mnh][mnw] == '#') continue;

//                     // 移動先が探索済みの場合
//                     if (magic_visited[mnh][mnw]) continue;
//                     if (foot_visited[mnh][mnw]) continue;
//                     //枝刈り
//                     if(magictriedto[mnh][mnw]) continue;
//                     else magictriedto[mnh][mnw] = true;

//                     foot_que.push({{mnh, mnw}, new_cnt});
//                 }
//             }
//         }
//     }

//     long long ans = magic[DH][DW];
//     if(ans == INF){
//         cout << -1 << endl;
//     }else{
//         cout << ans << endl;
//     }

// }
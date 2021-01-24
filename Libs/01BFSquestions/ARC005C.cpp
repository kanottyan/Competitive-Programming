//https://atcoder.jp/contests/arc005/tasks/arc005_3
//https://betrue12.hateblo.jp/entry/2018/12/08/000020


#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    long long H, W;
    cin >> H >> W;

    //score, first INF
    vector<vector<long long>> score(H, vector<long long>(W, INF));

    //make field
    vector<string> field(H);
    for(int i=0; i<H; ++i){
        cin >> field[i];
    }

    //get start and goal
    int sw, sh, gw, gh;
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            if(field[h][w] == 's'){
                sw = w, sh = h;
            }
            if(field[h][w] == 'g'){
                gw = w, gh = h;
            }
        }
    }

    // deqeue require info, x, y, cost
    // start from sx, sy
    deque<tuple<int, int, int>> que;
    que.emplace_back(sh, sw, 0);
    score[sh][sw] = 0;

    //01BFS
    while(!que.empty()){
        int h, w, c;
        tie(h, w, c) = que.front();
        que.pop_front();

        //距離が今よりも長かったら何もしない
        if(c > score[h][w]) continue;

        for(int dir=0; dir<4; ++dir){
            int nw = w + dy[dir];
            int nh = h + dx[dir];

            if( nh < 0 || H <= nh || nw < 0 || W <= nw ) continue;

            if(field[nh][nw] == '#'){
                if( c+1 < score[nh][nw] ){
                    score[nh][nw] = c+1;
                    que.emplace_back(nh, nw, c+1);
                }
            }else{
                if(c < score[nh][nw]){
                    score[nh][nw] = c;
                    que.emplace_front(nh, nw, c);
                }
            }
        }
    }



    if( score[gh][gw] <= 2 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
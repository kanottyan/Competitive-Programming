#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int h, w, n, m;


// 時計回り90度
void rotate(vector<vector<bool>> &a){
    int h = a.size(), w = a[0].size();
    vector<vector<bool>> pre(w, vector<bool>(h));
    swap(a, pre);
    for(int i=0; i<w; ++i){
        for(int j=0; j<h; ++j){
            a[i][j] = pre[h-1-j][i];
        }
    }
}

bool fn(int i, int j,
        vector<vector<bool>> &wall,
        vector<vector<bool>> &ok,
        vector<vector<bool>> &light,
        vector<vector<bool>> &visited,
        vector<vector<bool>> &memo
        ){
    if(i <0 || j <0 || i >= h || j >= w) return false;
    if(wall[i][j]) return false;
    if(light[i][j]) return true;
    if(visited[i][j]) return memo[i][j];
    visited[i][j] = true;
    //横にすすめる
    bool res = fn(i, j+1, wall, ok, light, visited, memo);
    memo[i][j] = res;
    return res;
}

int main(){
    cin >> h >> w >> n >> m;
    vector<vector<bool>> wall(h, vector<bool>(w));
    vector<vector<bool>> ok(h, vector<bool>(w));
    vector<vector<bool>> light(h, vector<bool>(w));
    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<vector<bool>> memo(h, vector<bool>(w));

    for(int i=0; i<n; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        light[a][b] = true;
    }

    for(int i=0; i<m; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        wall[a][b] = true;
    }

    for(int ri=0; ri<4; ++ri){
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                visited[i][j] = false;
            }
        }


        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                //横に行く
                if(fn(i,j, wall, ok, light, visited, memo)) ok[i][j] = true;
            }
        }

        //回転
        rotate(wall);
        rotate(ok);
        rotate(light);
        rotate(visited);
        rotate(memo);
        swap(h, w);
    }

    int ans = 0;
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(ok[i][j] == true ) ans++;
        }
    }

    cout << ans << endl;
}

// int main(){
//     int H, W, N, M;
//     cin >> H >> W >> N >> M;
    
//     vector<vector<int>> table(H, vector<int>(W,0));
//     vector<vector<int>> yoko(H, vector<int>(W,0));
//     vector<vector<int>> tate(H, vector<int>(W,0));

//     vector<int> Ah(N);
//     vector<int> Aw(N);
//     vector<int> Bh(M);
//     vector<int> Bw(M);

//     for(int i=0; i<N; ++i){
//         int a, b;
//         cin >> a >> b;
//         a--; b--;
//         Ah[i] = a; 
//         Aw[i] = b;
//     }

//     for(int i=0; i<M; ++i){
//         int c, d;
//         cin >> c >> d;
//         c--; d--;
//         Bh[i] = c; 
//         Bw[i] = d;
//         table[c][d] = -1;
//     }

//     //横方法
//     for(int i=0; i<N; ++i){
//         int h = Ah[i];
//         // //進む
//         for(int w=Aw[i]; w<W; ++w){
//             if(yoko[h][w] == 1) break;
//             if(table[h][w] == -1) break;
//             table[h][w] = 1;
//             yoko[h][w] = 1;
//         }

//         //戻る
//         for(int w=Aw[i]-1; w>=0; --w){
//             if(yoko[h][w] == 1) break;
//             if(table[h][w] == -1) break;
//             table[h][w] = 1;
//             yoko[h][w] = 1;
//         }
//     }


//     //縦方法
//     for(int i=0; i<N; ++i){
//         int w = Aw[i];
//         // //進む
//         for(int h=Ah[i]; h<H; ++h){
//             if(tate[h][w] == 1) break;
//             if(table[h][w] == -1) break;
//             table[h][w] = 1;
//             tate[h][w] = 1;
//         }

//         //戻る
//         for(int h=Ah[i]-1; h>=0; --h){
//             if(tate[h][w] == 1) break;
//             if(table[h][w] == -1) break;
//             table[h][w] = 1;
//             tate[h][w] = 1;
//         }
//     }

//     long long ans = 0;
//     for(int h=0; h<H; ++h){
//         for(int w=0; w<W; ++w){
//             if(table[h][w] == 1 ) ans++;
//         }
//     }


//     cout << ans << endl;

// }
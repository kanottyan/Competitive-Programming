#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int MOD = 1e9+7;

int main(){
    int H, W; cin >> H >> W;
    vector<string> table(H);

    vector<vector<long long>> score(H+1, vector<long long>(W+1));
    //累積和
    vector<vector<long long>> tate(H+1, vector<long long>(W+1));
    vector<vector<long long>> yoko(H+1, vector<long long>(W+1));
    vector<vector<long long>> naname(H+1, vector<long long>(W+1));


    for(int i=0; i<H; ++i){
        cin >> table[i];
    }

    score[1][1] = tate[1][1] = yoko[1][1] = naname[1][1] = 1;

    for(int i=1; i<=H; ++i){
        for(int j=1; j<=W; ++j){

            if(i ==0 && j==0) continue;
            if(table[i-1][j-1] == '#' ) continue;

            //上
            score[i][j] += tate[i-1][j];
            score[i][j] %= MOD;
            //左
            score[i][j] += yoko[i][j-1];
            score[i][j] %= MOD;
            //斜め
            score[i][j] += naname[i-1][j-1];
            score[i][j] %= MOD;

            //各累積和を更新
            tate[i][j] = tate[i-1][j] + score[i][j];
            tate[i][j] %= MOD;
            yoko[i][j] = yoko[i][j-1] + score[i][j];
            yoko[i][j] %= MOD;
            naname[i][j] = naname[i-1][j-1] + score[i][j];
            naname[i][j] %= MOD;
        }
    }

    cout << score[H][W] << endl;

    return 0;
}
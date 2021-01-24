#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int H, W; cin >> H >> W;
    vector<string> table(H);

    for(int h=0; h<H; ++h){
        cin >> table[h];
    }

    int ans = 0;

    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            //右におけるか
            if(w+1 < W && table[h][w] == '.' && table[h][w+1] == '.'){
                ans++;
            }
            //下におけるか
            if(h+1<H && table[h][w] == '.' && table[h+1][w] == '.'){
                ans++;
            }
        }
    }

    cout << ans << endl;
}
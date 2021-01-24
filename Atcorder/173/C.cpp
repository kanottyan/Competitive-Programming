#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> c(H, vector<char>(W));
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            cin >> c[h][w];
        }
    }


    int ans = 0;
    for(int hbit=0; hbit<(1 << (H)); ++hbit){
        for(int wbit=0; wbit<(1 << (W)); ++wbit ){
            int cnt = 0;

            for(int h=0; h<H; ++h){
                for(int w=0; w<W; ++w){
                    if( (hbit >> h & 1) || (wbit >> w &1) ){
                        continue;
                    }
                    if(c[h][w] == '#'){
                        cnt++;
                    }
                }
            }
            if(cnt == K){
                ans++;
            }

        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> A(W, vector<int>(H));

    for(int i=0; i<H; ++i)for(int j=0; j<W; ++j){
        int a; cin >> a;
        A[j][i] = a;
    }

    for(int j=0; j<W; ++j){
        for(int i=0; i<H; ++i){
            cout << A[j][i] << " ";
        }
        cout << endl;
    }
    


    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    int ans = 0;

    for(int i=0; i<N; ++i){
        int H; cin >> H;

        if( H > ans ) ans = H; else break;
        ans = max(ans, H);
    }

    cout << ans << endl;

    return 0;
}
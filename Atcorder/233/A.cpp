#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int X, Y; cin >> X >> Y;

    int ans = Y - X;
    if(ans <= 0){
        cout << 0 << endl;
    }else{
        //ans /= 10;

        //ans += 1;
        ans = (ans+9)/(10);

        cout << ans << endl;
    }

    return 0;
}
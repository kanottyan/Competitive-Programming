#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    double sx, sy, gx ,gy;
    cin >> sx >> sy >> gx >> gy;

    double ans = (sy*gx + sx*gy)/(sy+gy);
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
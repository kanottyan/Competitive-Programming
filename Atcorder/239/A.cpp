#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    double H; cin >> H;

    double ans = 12800000.0 + H;
    ans *= H;
    ans = sqrt(ans);

    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}
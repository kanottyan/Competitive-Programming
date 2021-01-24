#include <bits/stdc++.h>
using namespace std;
long long MINF = -1LL << 60;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long ans = MINF;
    ans = max(ans, a*c);
    ans = max(ans, a*d);
    ans = max(ans, b*c);
    ans = max(ans, b*d);



    cout << ans << endl;
}
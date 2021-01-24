#include <bits/stdc++.h>
using namespace std;

int main(){
    long long H; cin >> H;
    long long i = 0;
    long long ans = 0;

    while(H > 0){
        long long num = pow(2, i);
        ans += num;
        H /= 2;
        ++i;
    }

    cout << ans << endl;


}
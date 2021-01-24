#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, T;
    cin >> N >> X >> T;
    int cnt = N/X;
    int add = N % X;
    if(add != 0){
        cnt++;
    }

    int ans = cnt * T;

    cout << ans << endl;
}
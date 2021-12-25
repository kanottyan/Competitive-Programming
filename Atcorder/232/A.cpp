#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    string S; cin >> S;

    int a = S[0] - '0';
    int b = S[2] - '0';
    int ans = a * b;

    cout << ans << endl;

    return 0;
}
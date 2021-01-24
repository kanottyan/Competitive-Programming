#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    char S, T;
    cin >> S >> T;
    char ans;
    if(S == 'Y') ans = toupper(T);
    else ans = T;

    cout << ans << endl;
}
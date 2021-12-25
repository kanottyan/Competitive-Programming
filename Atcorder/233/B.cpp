#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int L, R; cin >> L >> R;
    L--; R--;
    string S; cin >> S;

    string ans = "";

    for(int i=0; i<L; ++i){
        ans += S[i];
    }

    string tmp = "";
    for(int i=L; i<=R; ++i){
        tmp += S[i];
    }
    reverse(tmp.begin(), tmp.end());

    ans = ans + tmp;
    for(int i=R+1; i<S.size(); ++i){
        ans += S[i];
    }

    cout << ans << endl;

    

    return 0;
}
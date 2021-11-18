#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    vector<string> S(3);
    for(int i=0; i<3; ++i) cin >> S[i];

    string T; cin >> T;
    string ans = "";

    for(int i=0; i<T.size(); ++i){
        int t = T[i] - '0';
        t--;
        ans += S[t];
    }

    cout << ans << endl;

    return 0;
    
}
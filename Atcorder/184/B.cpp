#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, X;
    cin >> N >> X;
    string s; cin >> s;

    int ans = X;
    for(int i=0; i<N; ++i){
        if(s[i] == 'o') ans++;
        if(s[i] == 'x' && ans >0) ans--;
    }

    cout << ans << endl;
    return 0;
}

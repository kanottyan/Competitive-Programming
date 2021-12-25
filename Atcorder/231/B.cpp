#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    int N; cin >> N;
    map<string, int> m;
    int num = 0;
    string ans = "";
    for(int i=0; i<N; ++i){
        string s; cin >> s;
        m[s]++;
        if(num <= m[s]) ans = s;
        num = max(num, m[s]);
    }
    
    cout << ans << endl;

    return 0;
}

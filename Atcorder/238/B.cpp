#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    set<int> s;
    s.insert(0);
    int dist = 0;
    for(int i=0; i<N; ++i){
        int A; cin >> A;
        int cut = (dist +A)%360;
        dist = cut;
        s.insert(cut);
    }

    int ans = 0;
    vector<int> v;
    v.assign(s.begin(), s.end());
    int prev = v[0];
    
    for(int i=0; i<v.size(); ++i){
        int n = v[i];
        ans = max(ans, n- prev);
        prev = n;
    }

    ans = max(ans, 360 - prev);

    cout << ans << endl;
    return 0;
}
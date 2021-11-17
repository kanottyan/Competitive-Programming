#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int N; cin >> N;
    map<int, int> m;
    for(int i=0; i<N; ++i){
        int n; cin >> n;
        m[n]++;
    } 

    int ans = 0;
    set<int> s;
    for(int a=1; a<1000; ++a){
        for(int b=a; b<1000; ++b){
            int res = 4*a*b + 3*a + 3*b;
            if(!m.count(res)) continue;
            if(s.count(res)) continue;
            ans += m[res];
            s.insert(res);
        }
    }

    cout << N-ans << endl;

    return 0;
}
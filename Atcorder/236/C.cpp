#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M; cin >> N >> M;
    vector<string> v;
    for(int i=0; i<N; ++i){
        string a; 
        cin >> a;
        v.push_back(a); 
    }

    set<string> s;
    for(int i=0; i<M; ++i){
        string aa; cin >> aa;
        s.insert(aa);
    }

    for(int i=0; i<N; ++i){
        if(s.count(v[i]) > 0) cout <<"Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
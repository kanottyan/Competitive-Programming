#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;



int main(){
    int N; cin >> N;

    set<int> s;
    set<int> removed;

    for(int i=0; i<=200000; ++i){
        s.insert(i);
    }

    for(int i=0; i<N; ++i){
        int p; cin >> p;
        if(s.count(p) > 0 && removed.count(p) == 0){
            s.erase(p);
            removed.insert(p);
        }

        cout << *s.begin() << endl;
    }

}
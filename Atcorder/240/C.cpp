#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    set<int> s;

    s.insert(0);

    for(int i=0; i<N; ++i){
        int a, b; cin >> a >> b;
        set<int> ns;
        for(int n : s){
            ns.insert(a + n);
            ns.insert(b + n);
        }
        swap(ns, s);
    }

    if(s.count(X) > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



    return 0;
}
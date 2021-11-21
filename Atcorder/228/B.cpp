#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, X; cin >> N >> X; X--;
    vector<int> A(N);
    for(int i=0; i<N; ++i){
        int a; cin >> a; a--;
        A[i] = a;
    }

    set<int> s;
    
    while(!s.count(X)){
        s.insert(X);
        X = A[X];
    }

    cout << s.size() << endl;


    return 0;
}
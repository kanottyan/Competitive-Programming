#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int V, A, B, C; cin >> V >> A >> B >> C;

    int cnt = 0;

    if(V >= (A+B+C)){
        V %= (A+B+C);
    }

    if(V - A < 0){
        cout << "F" << endl;
        return 0;
    }

    V -= A;
    if(V- B < 0){
        cout << "M" << endl;
        return 0;
    }

    cout << "T" << endl;


    return 0;
}
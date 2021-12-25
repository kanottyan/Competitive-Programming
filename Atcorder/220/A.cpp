#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    for(int i=1; i*C <= 1000; ++i){
        if(A <= C*i && C*i <= B){
            cout << C*i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
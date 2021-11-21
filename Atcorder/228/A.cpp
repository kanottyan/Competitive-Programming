#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int S, T, X;
    cin >> S >> T >> X;

    if(S < T){
        if(S <= X && X < T){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if( S<= X && X < 24){
            cout << "Yes" << endl;
        }else if( 0<= X && X < T){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int t; cin >> t;

    auto f = [&](auto t){
        return( t*t + t*2 + 3 );
    };

    cout << ( f(f(f(t)+t) + f(f(t))) ) << endl;


    return 0;
}
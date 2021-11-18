#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int x = 1; 
    const int& clref = x;

    int&& rref = 1+x;

    x = 100;

    cout << clref;

    return 0;
    
}
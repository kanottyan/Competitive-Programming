#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;
    N %= 2;

    if(N == 0){
        cout << "White" << endl;
    }else{
        cout << "Black" << endl;
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    double ans = 0;
    if(X <= A){
        ans = 1;
    }else if( A < X && X <= B){
        ans = (double) C/(double)(B-A);
    }else{
        ans = 0;
    }

    cout << setprecision(10) << fixed << ans << endl;

    return 0;
}
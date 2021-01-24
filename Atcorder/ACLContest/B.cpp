#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    string ans = "Yes";
    if(B < C || D < A){
        ans = "No";
    }
    
    cout << ans << endl;
    return 0;
}
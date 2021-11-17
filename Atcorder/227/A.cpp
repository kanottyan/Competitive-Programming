#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, K, A;
    cin >> N >> K >> A;

    int res = K%N;
    int ans = A+res-1;

    ans %= N;
    if(ans == 0){
        ans = N;
    }

    cout << ans << endl;

    return 0;
}
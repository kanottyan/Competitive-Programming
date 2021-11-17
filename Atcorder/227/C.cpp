#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    long long N; cin >> N;
    long long ans = 0;

    long long idx = 1;
    while(idx * idx * idx <= N){
        
        long long target = N/idx;
        
        for(long long a=idx; a<=(target/a); ++a){
            ans += (target/a-a +1);
        }
        idx++;
    }

    cout << ans << endl;

    return 0;
}
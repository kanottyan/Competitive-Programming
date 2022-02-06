#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;


int main(){

    long long N; cin >> N;

    string s = to_string(N);
    int digits = s.size();
    long long mult = 1;

    mint ans = 0;

    if( N < 10){
        cout << (1+N)*N/2 << endl;
        return 0;
    }

    for(int i=1; i<=digits-1; ++i){
        if(i == 1){
            ans += 45;
        }else{
            mint mx = mult;
            mx *= 10;
            mx -= 1;

            mint num = mx-mult;
            num += 1;
            mint tmp = (1 + num);
            tmp *= num;
            tmp /= 2;
            ans += tmp;
        }
        mult *= 10;
    }

    mint num = N - mult;
    num += 1;
    mint tmp = (1 + num);
    tmp *= num;
    tmp /= 2;
    ans += tmp;

    
    cout << ans.val() << endl;
    
    return 0;
}
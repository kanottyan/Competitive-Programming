#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, K, D;
    cin >> X >> K >> D;

    long long cnt = 0;
    cnt = abs(X)/D;
    long long ans;

    //残り回数
    if(K < cnt){
        ans = abs(X) - abs(D) * K;
    }else{
        K -= abs(X)/D;
        long long rest = abs(X)%D;

        if( K % 2 == 0){
            ans = rest;
        }else{
            long long candidate1 = abs(rest + D) ;
            long long candidate2 = abs(rest - D) ;
            ans = min( abs(candidate1), abs(candidate2) );
        }
    }
    cout << ans << endl;
}
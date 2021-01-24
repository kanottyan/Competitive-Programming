#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, K;
    cin >> N >> K;
    K = abs(K);

    long long X = 2*N;
    long long Y = X - K;

    long long ans = 0;
    while(Y > 1){
        long long Xa;
        if(X - N > 0){
            Xa = X - N;
        }else{
            Xa =X-1;
        }
        long long Xb = X - Xa;
        long long cntX = abs(Xa - Xb)+1;

        long long Ya;
        if(Y - N > 0){
            Ya = Y - N;
        }else{
            Ya = Y - 1;
        }
        long long Yb = Y - Ya;
        long long cntY = abs(Ya - Yb)+1;
        ans += (cntX * cntY);
        X--;
        Y--;
    }

    cout << ans << endl;
}
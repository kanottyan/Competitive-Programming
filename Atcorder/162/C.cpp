#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    if( b == 0 ) return a;
    else return gcd(b, a%b);
}

int main(){
    int K; cin >> K;
    long long ans = 0;
    for(int i=1; i<=K; ++i){
        for(int j=1; j<=K; ++j){
            for(int k=1; k<=K; ++k){
                long long g;
                g = gcd(i, j);
                g = gcd(g, k);
                ans += g;
            }
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> H(N);
    long long ans = 0;

    for(int i=0; i<N; ++i){
        cin >> H[i];
    }

    sort(H.rbegin(), H.rend());

    if( N <= K){
        ans = 0;
    }else{
        for(int i=K; i<N; ++i){
            ans += H[i];
        }
    }

    cout << ans << endl;
}
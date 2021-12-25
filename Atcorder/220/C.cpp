#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){
    long long N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    long long X; cin >> X;

    long long sum = 0;
    for(int i=0; i<N; ++i) sum += A[i];

    long long res = X%sum;
    long long ans = (X/sum)*N;

    for(int i=0; i<N; ++i){
        res -= A[i];
        ans ++;
        if(res < 0) break;
    }

    cout << ans << endl;


    return 0;
}
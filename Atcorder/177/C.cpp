#include<bits/stdc++.h>
#include<string>
using namespace std;

const int MOD = 1e9 + 7;


int main(){
    int N;
    cin >> N;
    vector<long long> A(N);

    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    vector<long long> cumsum(N);
    cumsum[0] = A[0];

    for(int i=1; i<N; ++i){
        cumsum[i] = cumsum[i-1] + A[i];
        cumsum[i] %= MOD;
    }

    long long res= 0;
    for(int i=0; i<N-1; ++i){
        res += cumsum[i] * A[i+1];
        res %= MOD;
    }

    cout << res << endl;
}
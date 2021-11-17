#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int N, K;

bool check(long long mid, const vector<long long > A){
    long long sum = 0;
    for(int i=0; i<N; ++i){
        sum += min(A[i], mid);
    }

    long long thresould = mid*K;

    if(sum >= thresould) return true; else return false;
}

int main(){

     cin >> N >> K;
    vector<long long> A(N);

    for(int i=0; i<N; ++i) cin >> A[i];

    // how many projects can be created
    long long ok = 1; 
    // consider overflow
    long long ng = 3e17/K;

    while(ng - ok >1){
        long long mid = (ok + ng)/2;

        if(check(mid, A))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}
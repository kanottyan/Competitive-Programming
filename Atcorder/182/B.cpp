#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// long long gcd(long long a, long long b){
//     if( b == 0) return a;
//     else return gcd( b, a%b);
// }

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    int max_gcd = 0;
    int max_num = -1;
    for(int i=2; i<=1000; ++i){
        int tmp = 0;
        for(int j=0; j<N; ++j){
            if(A[j]%i == 0) tmp++;
        }
        if(max_gcd <= tmp){
            max_gcd = tmp;
            max_num = i;
        }
    }

    cout << max_num << endl;

    return 0;
}
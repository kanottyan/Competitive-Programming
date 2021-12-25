#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


long long read(int k){
    string s;
    cin >> s;
    long long res = 0;

    for(char c : s){
        res = res*k + (c - '0');
    }
    return res;
}

int main(){
    int k; cin >> k;
    long long a = read(k);
    long long b = read(k);
    cout << a*b << endl;
}

// int main(){
//     int K; cin >> K;
//     string A, B; cin >> A >> B;
//     long long iA=0, iB=0;

//     int p = 0;
//     for(int pos=A.size()-1; pos>=0; --pos){
//         long long num = A[pos] - '0';
//         iA += num*pow(K, p);
//         p++;
//     }

//     p = 0;
//     for(int pos=B.size()-1; pos>=0; --pos){
//         long long num = B[pos] - '0';
//         iB += num*pow(K, p);
//         p++;
//     }
//     long long ans = iA * iB;

//     cout << ans << endl;

//     return 0;
// }
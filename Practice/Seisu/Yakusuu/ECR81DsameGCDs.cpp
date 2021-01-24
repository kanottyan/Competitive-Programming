//https://codeforces.com/contest/1295/problem/D
//https://qiita.com/drken/items/0c88a37eec520f82b788#問題-9-educational-codeforces-round-81-d-same-gcds

// #include <iostream>
// #include <vector>
// using namespace std;

// long long GCD(long long a, long long b) {
//     if (b == 0) return a;
//     else return GCD(b, a % b);
// }

// vector<pair<long long, long long> > prime_factorize(long long N) {
//     vector<pair<long long, long long> > res;
//     for (long long a = 2; a * a <= N; ++a) {
//         if (N % a != 0) continue;
//         long long ex = 0;
//         while (N % a == 0) {
//             ++ex;
//             N /= a;
//         }
//         res.push_back({a, ex});
//     }
//     if (N != 1) res.push_back({N, 1});
//     return res;
// }

// int main() {
//     int T; cin >> T;
//     for (int _ = 0; _ < T; ++_) {
//         long long a, m;
//         cin >> a >> m;
//         long long g = GCD(a, m);
//         m /= g;
//         const auto &pf = prime_factorize(m);
//         long long res = m;
//         for (auto p : pf) res = res / p.first * (p.first-1);
//         cout << res << endl;
//     }
// }

#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long A, long long B){
    if(B == 0) return A;
    else return GCD(B, A%B);
}

vector<pair<long long, long long> > prime_fac(long long N){
    vector<pair<long long, long long> > res;

    for(long long  i=2; i*i<=N; ++i){
        if(N%i != 0) continue;
        long long ex = 0;

        while(N%i ==0){
            ex++;
            N /= i;
        }
        res.push_back({i, ex});
    }

    if(N != 1) res.push_back({N, 1});
    return res;
}

long long solve(long long a, long long x){
    long long g = GCD(a, x);
    long long x_dot = x/g; 

    const auto& res = prime_fac(x_dot);
    long long ans = x_dot;
    for(auto p: res){
        ans /= p.first;
        ans *= (p.first - 1);
    }
    return ans;
}

int main(){

    int T;
    cin >> T;
    for(int i=0; i<T; ++i){
        long long a, x;
        cin >> a >> x;
        cout << solve(a, x) << endl;
    }

}
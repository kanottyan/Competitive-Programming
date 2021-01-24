//https://atcoder.jp/contests/abc142/tasks/abc142_d
//https://qiita.com/drken/items/a14e9af0ca2d857dad23#問題-9-abc-142-d---disjoint-set-of-common-divisors-400-点

#include <vector>
#include <iostream>
#include <map>

using namespace std;

//A must larger than B
long long gcd(long long A, long long B){
    if(B ==0) return A;
    else return gcd(B, A % B);
}

vector<pair<long long, long long> > prime_fac(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

// can't use map ! as insert takes time(LogN)
// map<long long, long long> prime_fac(long long N){
//     map<long long, long long> res;
//     for(long long i=2; i<N; ++i){
//         if(N%i != 0) continue;
//         long long ex = 0;

//         while(N%i ==0){
//             ex++;
//             N /= i;
//         }
        
//         res[i] = ex;
//     }
//     if(N != 1) res[N] = 1;

//     return res;
// }


int main(){
    long long A, B;
    cin >> A >> B;

    long long g = gcd(A, B);
    // all the numbers should have 1 as the prime 
    const auto& res = prime_fac(g);
    long long ans = 1 + (long long)res.size();
       cout << ans << endl;

}
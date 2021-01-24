//https://community.topcoder.com/stat?c=problem_statement&pm=11227&rd=14243
// https://qiita.com/drken/items/0c88a37eec520f82b788#6-3-倍数の周期性

#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

class Starport {
public:
    double getExpectedTime(long long N, long long M) {
        long long g = GCD(N, M);
        N /= g; M /= g;
        return (double)(N-1)*g/2;
    }
};

// ワイの答え
// #include <vector>
// #include <iostream>

// using namespace std;

// long long gcd(long long A, long long B){
//     if(B == 0) return A;
//     else return gcd(B, A%B);

// }

// int main(){
//     int N, M; //N:port open time, //M:startship arrival time
//     cin >> N >> M;

//     long long g = gcd(N, M);
//     long long n = N/g;
//     long long m = M/g;

//     double sum = ((double)n-1.0) / 2.0 * ((double)n);
//     sum = sum * (double)g;
//     double res = sum/n;

//     cout << res << endl;
// }
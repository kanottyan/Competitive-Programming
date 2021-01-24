//https://atcoder.jp/contests/abc148/tasks/abc148_c
//https://qiita.com/drken/items/0c88a37eec520f82b788

#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    long long g = gcd(a, b);
    return a/g * b;
}

int main(){
    long long A, B;
    cin >> A >> B;

    long long ans = lcm(A, B);
    cout << ans << endl;
}
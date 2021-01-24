//https://yukicoder.me/problems/no/442
//https://qiita.com/drken/items/0c88a37eec520f82b788#4-互いに素への帰着

#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long A, long long B){
    if(B == 0) return A;
    else return gcd(B, A % B);
}

int main(){
    long long A, B;
    cin >> A >> B;

    long long g = gcd(A, B);
    long long ans = g * gcd(A / g + B / g, g);


    cout << ans << endl;
}
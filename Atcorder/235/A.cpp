#include <bits/stdc++.h>
#include <atcoder/all> 

using namespace std;
using namespace atcoder;

int main(){

    char a, b, c;
    cin >> a >> b >> c;

    int A = a - '0';
    int B = b - '0';
    int C = c - '0';

    int abc = A * 100 + B * 10 + C;
    int bca = B * 100 + C * 10 + A;
    int cab = C * 100 + A * 10 + B;

    int res = abc + bca + cab;

    cout << res << endl;

    return 0;
}
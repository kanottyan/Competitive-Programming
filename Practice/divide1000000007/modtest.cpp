#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
  long long a, b, c;
  a = 111111111;
  b = 123456789;
  c = 987654321;
  cout << a * b * c % MOD << endl;       // a*b*c がオーバーフローするので間違った答えに
  cout << a * b % MOD * c % MOD << endl; // a*b で一旦 MOD をとる
}

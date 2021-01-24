#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;          // 要素数
  int a[100000];  // 要素数 100000 以下とします
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i];

  sort(a, a + N);  // a[0:N] を小さい順にソート

  // 出力
  for (int i = 0; i < N; ++i) cout << a[i] << " ";
  cout << endl;
}
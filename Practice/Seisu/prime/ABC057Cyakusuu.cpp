//C - Digits in Multiplication
//https://atcoder.jp/contests/abc057/tasks/abc057_c

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int _count_digit( long long num){
    int count = 1;
    while(num / 10 > 0){
        count++;
        num /=10;
    }

    return count;
}

int get_large_digit(long long A, long long B){
    return max( _count_digit(A), _count_digit(B) );
}

int main() {
    long long N;
    cin >> N;

    int ans = INT_MAX;
    for (long long i = 1; i * i <= N; ++i) {

        if (N % i == 0) {
            int tmp = get_large_digit( i, N/i );
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;

    int i = 1<<29;
    cout << i << endl;
}

//qiita

#include <iostream>
using namespace std;

int calc_digit(long long N) {
    int res = 0;
    while (N) {
        ++res;
        N /= 10;
    }
    return res;
}

int main() {
    long long N;
    cin >> N;
    int res = (1<<29); // 十分大きい値で初期化
    for (long long A = 1; A * A <= N; ++A) {
        if (N % A == 0) {
            long long B = N / A;
            int F = max(calc_digit(A), calc_digit(B));
            res = min(res, F);
        }
    }
    cout << res << endl;
}
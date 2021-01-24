#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    //long long sum = 0;
    vector<int> sum(N+1,0);

    // 計算例
    // for(int i=K; i<=N+1; ++i){
    //     long long max=0;
    //     long long min=0;
    //     for(int j=0; j<i; ++j){
    //         min += j;
    //     }
    //     for(int j=N; j> N-i; --j){
    //         max += j;
    //     }
    //     sum += (max - min+1);
    // }
    long long cumsum = 1;
    sum[K-1] = 1;
    for(int i=K; i<=N; ++i){
        cumsum +=i;
        sum[i] = (sum[i-1] + cumsum)%MOD;
    }

    long long res = sum[N] % MOD;
    cout << res << endl;
}
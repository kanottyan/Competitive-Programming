//https://atcoder.jp/contests/dp/tasks/dp_b

// https://qiita.com/drken/items/dc53c683d6de8aeacf5a

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long INF =  1LL << 60;
long long dp[101000];

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> hight(N);
    //init
    for(int i=0; i<N; ++i) cin >> hight[i];
    for(int i=0; i<N; ++i) dp[i] = INF;


    dp[0] = 0;
    dp[1] = abs(hight[1]- hight[0]);

    for(int i=0; i<N; ++i){
        for(int j=i+1; j<=i+K; ++j){
            dp[j] = min( dp[j], dp[i] + abs(hight[i] - hight[j]));
        }
    }
    cout << dp[N-1] << endl;

}

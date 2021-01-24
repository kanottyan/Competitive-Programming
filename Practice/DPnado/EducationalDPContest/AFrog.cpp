// https://qiita.com/drken/items/dc53c683d6de8aeacf5a

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 100100100;
int dp[101000];

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<int> hight(N);
    //init
    for(int i=0; i<N; ++i) cin >> hight[i];
    for(int i=0; i<N; ++i) dp[i] = INF;


    dp[0] = 0;
    dp[1] = abs(hight[1]- hight[0]);

    if(N <= 2){
        cout << dp[1] << endl;
    }else{
        for(int i=2; i<N; ++i){
            dp[i] = min( dp[i-2] + abs(hight[i]- hight[i-2]), dp[i-1] + abs(hight[i] - hight[i-1]));
        }
        cout << dp[N-1] << endl;
    }
}
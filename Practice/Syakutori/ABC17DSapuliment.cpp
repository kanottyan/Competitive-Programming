//https://atcoder.jp/contests/abc017/tasks/abc017_4

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int dp[110000];
int sum[11000];

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);

    for(int i=0; i<N; ++i) cin >> a[i], --a[i];

    dp[0] = 1;

    /*尺取方*/
    vector<int> funm(M, 0);// 区間に種類 i が何個あるか
    vector<int> L(N+1, 0);// 各 i に対するしゃくとり法の区間
    int left = 0;
    
    for(int right =0; right <N; ++right){
        funm[a[right]]++;//薬品iが出たのとカウント
        while(left< right && funm[a[right]] > 1){
            --funm[a[left]];
            ++left;
        }
        L[right+1] = left;
    }

    /*累積わ*/
    dp[0] = 1;
    sum[0] = 0; sum[1] =1;

    for(int i=1; i<=N; ++i){
        dp[i] = (sum[i] - sum[L[i]] + MOD) %MOD; //dp[i]
        sum[i+1] = (sum[i] + dp[i]) %MOD; //ruiseki
    }
    cout << dp[N] << endl;
}
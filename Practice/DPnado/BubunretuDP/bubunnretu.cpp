//https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd

// 【問題概要】
// 長さ n
//  の文字列 S
//  が与えられる。
// S
//  の部分文字列 (空文字含む) として考えられるものの個数を数え上げよ。ただし答えがとても大きくなることがあるので、個数を 1,000,000,007 で割ったあまりを求めよ。
// 【制約】
// 1≤n≤105
// S
//  に登場する文字は英小文字のみ (26 種類)
// 【数値例】
// S
//  = "abcde" のとき、32 通り (全文字が異なるので 25=32
//  通り)
// S
//  = "aaaaa" のとき、6 通り ("", "a", "aa", "aaa", "aaaa", "aaaaa")
// S
//  = "aba" のとき、7 通り ("", "a", "b", "aa", "ab", "ba", "aba")

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string &S){
    int n = (int) S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for(int i=n-1; i>=0; --i){
        for(int j=0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

//mod world add
void add(long long &a, long long b){
    a += b;
    if(a >= MOD) a-=MOD;
}

int main(){
    //input
    string S; cin >> S;
    int n = (int)S.size();

    //pre array processing
    vector<vector<int> > next = calcNext(S);

    //DP
    vector<long long> dp(n+1, 0);
    dp[0] = 1;//init,, 0 corresponds to "".
    for(int i=0; i < n; ++i){
        for(int j=0; j < 26; ++j){
            if(next[i][j] >= n) continue; // if no more nexzt char j, then ignore
            add(dp[next[i][j] + 1], dp[i]);
        }
    }

    long long res = 0;
    for(int i = 0; i <= n; ++i) add(res, dp[i]);

    cout << res << endl;
}
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2895

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

    cout << res << endl;
}
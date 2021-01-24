//https://atcoder.jp/contests/abc118/tasks/abc118_c
//https://qiita.com/drken/items/0c88a37eec520f82b788#問題-3-abc-118-c---monsters-battle-royale-300-点

#include <vector>
#include <iostream>

using namespace std;

long long gcd(long long A, long long B){
    if(B == 0) return A;
    else return gcd(B, A%B);
}

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; ++i){
        cin >> a[i]; 
    }

    long long ans = 0;
    for(int i=0; i<N; ++i){
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;

}
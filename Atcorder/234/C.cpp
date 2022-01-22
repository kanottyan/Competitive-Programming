#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long K; cin >> K;
    stack<long long> s;

    if(K == 1){
        cout << 2 << endl;
        return 0;
    }

    while(K >= 2){
        s.push(K%2);
        K /=2;
    }

    if(K > 0) s.push(K);

    while(!s.empty()){
        int n = s.top();
        s.pop();
        cout << n*2 ;
    }
    cout << endl;

    return 0;
}
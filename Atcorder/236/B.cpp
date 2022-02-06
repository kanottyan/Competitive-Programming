#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N; cin >> N;
    int m = 2*(1+N)*N;

    for(int i=0; i<4*N-1; ++i){
        int a; cin >> a;
        m -= a;
    }
    
    cout << m << endl;

    return 0;
}
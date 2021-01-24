#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int a, b; cin >> a >> b;
    string ans = "";

    if(a <= b){
        for(int i=0; i<b; ++i){
            ans += to_string(a);
        }
    }else{
        for(int i=0; i<a; ++i){
            ans += to_string(b);
        }
    }

    cout << ans << endl;
}
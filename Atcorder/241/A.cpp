#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int a[10];
    for(int i=0; i<10; ++i) cin >> a[i];

    int ans = a[0];
    ans = a[ans];
    ans = a[ans]; 

    cout << ans << endl;

    return 0;
}
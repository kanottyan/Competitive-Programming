#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    string s; cin >> s;
    int a, b; cin >> a >> b;
    a--; b--;
    swap(s[a], s[b]);
    cout << s << endl;
    return 0;
}
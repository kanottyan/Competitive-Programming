#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    vector<int> a(4);
    for(int i=0; i<4; ++i){
        cin >> a[i];
    }

    auto res = min_element(a.begin(), a.end());
    cout << *res << endl;

}
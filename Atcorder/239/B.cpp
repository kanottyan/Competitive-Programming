#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    string X; cin >> X;
    if(X.size() == 1 ){
        cout << 0 << endl;
        return 0;
    }

    if(X.size() == 2 && stoi(X) < 0){
        cout << -1 << endl;
        return 0;
    }


    string ans = X.substr(0, X.size()-1);
    if(ans[0] == '-' && X[X.size()-1] != '0'){
        string s = "";
        s = ans.substr(1, ans.size()-1);

        unsigned long long ull;
        std::string::size_type sz = 0;        

        ull = stoull(s, &sz, 0);
        ull+=1;
        s =to_string(ull);
        ans = "-" + s;
        
    }

    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    string ans;
    for(int i=0; i<s.size(); ++i){
        if(s[2] == s[3] && s[4] == s[5]) ans = "Yes";
        else ans = "No";
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool flag;
    int ans = 0;

    for(int i=0; i<s.size(); ++i){
        int digit = s[i] - '0';
        ans += digit % 9;
        ans %= 9;
    }

    if(ans %9 == 0){
        flag = true;
    }else{
        flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
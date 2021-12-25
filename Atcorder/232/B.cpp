#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    string S, T; cin >> S >> T;

    string alpha = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    bool flag = false;


    for(int i=0; i<26; ++i){
        string newS = "";

        for(int j=0; j<S.size(); ++j){
            int cur = S[j] - 'a';
            cur += i;
            newS += alpha[cur];
        }

        if(newS == T){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
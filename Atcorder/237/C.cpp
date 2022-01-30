#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    map<char, int> m;
    string S; cin >> S;

    int head_a = 0;
    int tail_a = 0;
    int is_palindrome = true;

    if(S[0] == 'a'){
        for(int i=0; i<S.size(); ++i){
            if(S[i] == 'a') head_a++;
            else break;
        }
    }

    if(S[S.size()-1] == 'a'){
        for(int i=S.size()-1; i>=0; --i){
            if(S[i] == 'a') tail_a++;
            else break;
        }
    }

    for(int i=0; i<S.size()/2; ++i){
        if(S[i] != S[S.size()-1-i]) is_palindrome = false;
    }

    string s = "";

    if(!is_palindrome){
        for(int i=0; i<tail_a - head_a; ++i) s += 'a';
        s += S;
    }else{
        cout << "Yes" << endl;
        return 0;
    }

    is_palindrome = true;
    for(int i=0; i<s.size()/2; ++i){
        if(s[i] != s[s.size()-1-i]) is_palindrome = false;
    }

    if(is_palindrome){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
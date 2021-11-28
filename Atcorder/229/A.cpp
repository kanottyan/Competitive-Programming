#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    string s1, s2; cin >> s1 >> s2;

    int tot = 0;
    if(s1[0] == '#') tot++;
    if(s1[1] == '#') tot++;
    if(s2[0] == '#') tot++;
    if(s2[1] == '#') tot++;

    bool flag= false;
    if(tot >= 2){
        if(tot == 2){
            if( s1[0] == '#' && s2[1] == '#' ){
                flag = false;
            }else if( s1[1] == '#' && s2[0] == '#' ){
                flag = false;
            }
            else{
                flag = true;
            }
        }else{
            flag = true;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
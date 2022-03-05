#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){
    int a,b ; cin >> a >> b;
    bool flag =false;
    if(abs(a-b) == 1) flag = true;
    if(a == 1 && b == 10) flag = true;

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
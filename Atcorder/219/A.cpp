#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int X; cin >> X;

    int ans = 0;

    if( 0<= X && X < 40){
        ans = 40 -X;
    }else if(40 <= X && X < 70){
        ans = 70 - X;
    }else if(70 <= X && X < 90 ){
        ans = 90 -X;
    }else{
        ans = 101;
    }
    
    if(ans == 101){
        cout << "expert" << endl;
    }else{
        cout << ans << endl;
    }


    return 0;   
}
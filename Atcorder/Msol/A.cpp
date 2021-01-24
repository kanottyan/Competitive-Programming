#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    int X; cin >> X;
    int ans;
    if( 400 <= X && X <= 599){
        ans = 8;
    }else if(600 <= X && X <= 799){
        ans = 7;
    }else if(800 <= X && X<= 999){
        ans = 6;
        
    }else if(1000 <= X && X<= 1199){
        ans = 5;
        
    }else if(1200 <= X && X<= 1399){
        ans = 4;
        
    }else if(1400 <= X && X<= 1599){
        ans = 3;
        
    }else if(1600 <= X && X<= 1799){
        ans = 2;
        
    }else if(1800 <= X && X<= 1999){
        ans = 1;
    };

    cout << ans << endl;
}
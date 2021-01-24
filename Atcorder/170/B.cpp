#include <iostream>
#include <vector>

using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;

    bool flag = false;
    //iつる
    for(int turu=0; turu<=X; ++turu){
        int kame = X - turu;
        if( (turu * 2) + (kame * 4) == Y) flag = true;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
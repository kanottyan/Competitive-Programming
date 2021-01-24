#include <iostream>
#include <vector>

using namespace std;

int main(){
    int X;
    cin >> X;

    int x = 1;

    while( !((X*x)%360 == 0)){
        x++;
    }

    cout << x << endl;
}
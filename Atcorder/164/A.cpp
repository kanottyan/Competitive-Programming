#include <vector>
#include <iostream>

using namespace std;

int main(){

    int S, W;
    cin >> S >> W;

    if(W >= (S+1/2)){
        cout << "unsafe" << endl;
    }else{
        cout << "safe" << endl;
    }
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long long X;

    cin >> X;

    for(long long i=-200; i<=200; ++i){
        for(long long j=-200; j<=200; ++j){
            //long long calc = (i*i*i*i*i) - (j*j*j*j*j);
            long long calc = pow(i, 5) - pow(j, 5);
            if(calc == X){
                cout << i << " ";
                cout << j << endl;
                return true;
            }
        }
    }

    return true;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long X;
    cin >> X;

    long long money = 100;
    long long year = 0;


    while(money < X){
        money = money*(1 + 0.01);
        year++;
    }

    cout << year << endl;
}
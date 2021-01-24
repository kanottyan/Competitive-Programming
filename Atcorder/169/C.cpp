#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    //1000000000000 0.56
    //1000000000000 0.59
    //999990000000001 9.99 --> 9989900100000009

    long long A;
    float B;
    cin >> A >> B;
    long long prev = A*B;
    B = B*100 + 0.5;
    double seisuuB;
    modf(B, &seisuuB);
    cout << fixed << setprecision(15) << seisuuB << endl;
    cout << fixed << setprecision(15) << (int)seisuuB << endl;

    long long res = A*seisuuB;
    long long resB = A*(int)seisuuB;




    cout << res << endl;
}
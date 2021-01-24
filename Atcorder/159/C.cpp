#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double L;
    cin >> L;

    double ans = pow((L/3), 3);

    cout << fixed << setprecision(15) << ans << endl;
    
}
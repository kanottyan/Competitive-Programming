#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long ans = N + pow(N,2) + pow(N,3);

    cout << ans << endl;
}
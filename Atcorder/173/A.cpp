#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    while(N > 1000){
        N -= 1000;
    }

    int ans = 1000 - N;

    cout << ans << endl;
}
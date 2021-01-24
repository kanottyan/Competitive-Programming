#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;


    long long cnt = 0;
    while(N > 0){
        N /= K;
        cnt++;
    }

    cout << cnt << endl;
}
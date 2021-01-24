#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N, R;
    cin >> N >> R;
    if(N >= 10){
        cout << R << endl;
    }else{
        int res = R + (100 * (10 - N));
        cout << res << endl;
    }
}
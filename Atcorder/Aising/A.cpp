#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int L, R;
    cin >> L >> R;

    int d;
    cin >> d;

    int ans = 0;
    for(int i=L; i<=R; ++i){
        if(i % d == 0) ans++;
    }


    cout << ans << endl;
}
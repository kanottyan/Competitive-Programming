#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int A, B;
    cin >> A >> B;

    int ans = -1;
    for(int i=1; i<=1000; ++i){
        if( (i*8)/100 == A and (i*10)/100 == B){
            ans = i;
            break;
        }
    }

    cout << ans << endl;


}
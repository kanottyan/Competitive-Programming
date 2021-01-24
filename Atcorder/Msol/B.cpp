#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    int K; cin >> K;

    while( K > 0){
        if(A >= B){
            B *= 2;
        }else if(A >= C){
            C *= 2;
        }else if( B >= C){
            C *= 2;
        }
        K--;
    }

    string ans = "No";
    if( A < B && B < C){
        ans = "Yes";
    }

    cout << ans << endl;
}
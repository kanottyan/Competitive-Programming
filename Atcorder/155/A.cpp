#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    string ans = "No";
    if(A == B && A != C){
        ans = "Yes";
    }else if(A ==C && A != B){
        ans = "Yes";
    }else if(B == C && C != A){
        ans = "Yes";
    }

    cout << ans << endl;
}
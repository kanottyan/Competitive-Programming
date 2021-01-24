#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    string ans = "APPROVED";

    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    for(int i=0; i < N; ++i){
        if( A[i]%2 == 0){
            if( A[i] % 3 != 0 && A[i] % 5 !=0 ){
                ans = "DENIED";
            }
        }
    }
    cout << ans << endl;
}
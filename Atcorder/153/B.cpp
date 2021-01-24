#include <bits/stdc++.h>
using namespace std;


int main(){
    long long H;
    int N;
    cin >> H >> N;
    vector<long long> A(N);

    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    for(int i=0; i<N; ++i){
        H -= A[i];
        if(H <= 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No"<< endl;
    return 0;
}
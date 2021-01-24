#include <bits/stdc++.h>
using namespace std;

int main(){

    long long N; 
    cin >> N;
    vector<long long> A(N);
    
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    long long cnt = 0;
    long long current_hight = A[0];

    for(int i=1; i<N; ++i){
        if(current_hight >= A[i]){
            cnt += current_hight - A[i];
        }else{
            current_hight = A[i];
        }

    }

    cout << cnt << endl;


}
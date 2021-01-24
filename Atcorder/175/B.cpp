#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;
    vector<int> L(N);
    for(int i=0; i<N; ++i){
        cin >> L[i];
    }

    int cnt = 0;
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            for(int k=j+1; k<N; ++k){
                if(L[i] + L[j] > L[k] && 
                L[i] + L[k] > L[j] &&
                L[j] + L[k] > L[i] && 
                L[i] != L[j] &&
                L[j] != L[k] &&
                L[i] != L[k]){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}
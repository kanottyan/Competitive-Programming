#include <bits/stdc++.h>
using namespace std;


int main(){
    set<long long> s;

    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    bool flag = true;
    for(int i=0; i<N; ++i){
        if( s.count(A[i]) > 0 ){
            flag = false;
            break;
        }

        s.insert(A[i]);
    }

    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
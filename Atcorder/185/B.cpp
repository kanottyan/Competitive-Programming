#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N;
    int M;
    long long T;
    cin >> N >> M >> T;
    vector<pair<int, int>> p(M);

    for(int i=0; i<M; ++i){
        cin >> p[i].first;
        p[i].first *= 2;
        cin >> p[i].second; 
        p[i].second *= 2;
    }

    bool flag = true;
    long long prev = 0;
    int Max_N = N;

    for(int i=0; i<M; ++i){
        N -= (p[i].first+1 - prev)/2;
        if(N <= 0){
            flag = false;
            break;
        }
        N += (p[i].second - p[i].first +1)/2;
        if(N >= Max_N) N = Max_N;
        prev = p[i].second;
    }

    N -= ( T*2 - prev)/2;
    if(N <= 0){
        flag = false;
    }


    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
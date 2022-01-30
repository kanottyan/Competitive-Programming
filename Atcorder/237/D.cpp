#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    string S; cin >> S;

    for(int i=0; i<N; ++i){
        if(S[i] == 'L'){
            S[i] = 'R';
            continue;
        } 
        if(S[i] == 'R'){
            S[i] = 'L';
            continue;
        } 
    }
    reverse(S.begin(), S.end());

    deque<int> dq;
    dq.push_back(N);
    for(int i=0; i<N; ++i){
        if(S[i] == 'R'){
            dq.push_back(N-i-1);
        }else{
            dq.push_front(N-1-i);
        }
    }

    for(int e : dq){
        cout << e << " ";
    }

    return 0;
}
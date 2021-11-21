#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, K; cin >> N >> K;
    vector<int> P(N, 0);

    for(int i=0; i<N; ++i){
        int p1, p2, p3; cin >> p1 >> p2 >> p3;
        P[i] += (p1 + p2 + p3);
    }
    vector<int> A = P;
    sort(A.begin(), A.end());
    int thresold = A[N-K];

    for(int i=0; i<N; ++i){
        if(P[i] + 300 >= thresold){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
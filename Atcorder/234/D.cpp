#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, K; cin >> N >> K;
    vector<int> P(N);
    for(int i=0; i<N; ++i)  cin >> P[i];

    for(int i=0; i<K; ++i) pq.push(P[i]);
    cout << pq.top() << endl;

    for(int i=K; i<N; ++i){
        int Kth = pq.top();
        int cur = P[i];
        if(P[i] < Kth){
            cout << pq.top() << endl;
            continue;
        }
        pq.pop();
        pq.push(P[i]);
        cout << pq.top() << endl;
    }

    return 0;
}
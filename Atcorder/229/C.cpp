#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    long long N, W; cin >> N >> W;

    priority_queue< pair<long long , long long>,  vector<pair<long long , long long>>> pq;
    long long ans = 0;

    for(int i=0; i<N; ++i){
        long long a, b; cin >> a >> b;
        pq.emplace(a, b);
    }

    while(!pq.empty()){
        pair<long long , long long> e = pq.top();
        pq.pop();
        
        if( W < e.second){
            long long rest = min(W, e.second);
            ans += e.first * rest;
            break;
        }
        ans += e.first*e.second;
        W -= e.second;
    }

    cout << ans << endl;


    return 0;
}
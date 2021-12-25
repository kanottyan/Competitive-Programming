#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N, K; cin >> N >> K;
    vector<long long> A(N);
    vector<long long> cumsum(N+1);
    cumsum[0] = 0;
    for(int i=0; i<N; ++i) cin >> A[i];

    map<long long, long long> m;
    m[0] = 1;
    for(int i=0; i<N; ++i){
        cumsum[i+1] = (cumsum[i] + A[i]);
        m[cumsum[i+1]]++;
    }

    // if you check from head to tail, then has to consider the edge case
    if(m.size() == 1 && m[0] > 1 ) m[0]--;

    long long ans = 0;
    for(int i=0; i<N+1; ++i){
        long long target = cumsum[i]+K;
        if(m.count(target)) ans += m[target];

        if(m.count(cumsum[i])){
            if(m[cumsum[i]] > 1){
                m[cumsum[i]]--;
            }else{
                m.erase(cumsum[i]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

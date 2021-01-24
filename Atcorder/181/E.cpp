#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const long long INF = __LONG_LONG_MAX__;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n);
    vector<long long> w(m);
    vector<long long> delta_front(n/2+2, 0);
    vector<long long> delta_cumsum_front(n/2+2, 0);

    vector<long long> delta_back(n/2+2, 0);
    vector<long long> delta_cumsum_back(n/2+2, 0);


    for(long long i=0; i<n; ++i) cin >> h[i];
    for(long long i=0; i<m; ++i) cin >> w[i];
    h[n] = INF;

    sort(h.begin(), h.end());

    for(long long i=0; i<n-1; ++i){
        if(i%2 == 0){
            delta_front[i/2+1] = h[i+1] - h[i]; 
        }else{
            delta_back[i/2+1] = h[i+1] - h[i];
        }
    }

    for(int i=0; i<n/2+1; ++i){
        delta_cumsum_front[i+1] += delta_cumsum_front[i];
        delta_cumsum_front[i+1] += delta_front[i+1];

        delta_cumsum_back[i+1] += delta_cumsum_back[i];
        delta_cumsum_back[i+1] += delta_back[i+1];
    }

    long long ans = INF;

    for(long long i=0; i<m; ++i){
        auto p = lower_bound( h.begin(), h.end(), w[i] );
        long long idx = distance( h.begin(), p);
        long long new_pair = 0;
        if(idx%2 == 0){
            //右とつける
            new_pair = h[idx] - w[i];
        }else{
            //左とつける
            new_pair = w[i] - h[idx-1];
        }

        long long tmp = 0;
        long long a = delta_cumsum_front[idx/2];
        long long b = delta_cumsum_back[n/2+1] - delta_cumsum_back[idx/2];
        long long c = new_pair;
        tmp += (a+b+c);
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
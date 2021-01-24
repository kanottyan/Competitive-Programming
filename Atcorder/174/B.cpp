#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(){
    long long N, D;
    cin >> N >> D;
    vector<pair<long long, long long>> P(N);
    for(int i=0; i<N; ++i){
        long long X, Y; cin >> X >> Y;
        P[i] = {X, Y};
    }

    int ans = 0;
    for(int i=0; i<N; ++i){
        long long dist = P[i].first * P[i].first + P[i].second* P[i].second;
        long long limit = D * D;
        if(dist <= limit) ans++;
    }

    cout << ans << endl;
}
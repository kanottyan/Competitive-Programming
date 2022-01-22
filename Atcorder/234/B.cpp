#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    long long dist = 0;
    vector<pair<int, int>> points(N);

    for(int i=0; i<N; ++i){
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }


    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            long long dx = abs( points[i].first - points[j].first );
            long long dy = abs( points[i].second - points[j].second);

            dist = max(dist, dx*dx + dy*dy);
        }
    }

    cout << fixed << setprecision(10) << sqrt(dist) << endl;


    return 0;
}
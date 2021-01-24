#include <bits/stdc++.h>
#include <set>
using namespace std;

const long long INF = 1LL << 60;

int main(){
    int N; cin >> N;

    vector<pair<long long, long long>> p(N);
    long long max_dist = 0;
    set<pair<long long, long long>> candidates;

    //中心を真ん中にずらす
    for(int i=0; i<N; ++i){
        long long x, y;
        cin >> x >> y;
        p[i] = {x, y};

        long long dist = abs(x-5e8) + abs(y-5e8);

        if( max_dist < dist ){
            max_dist = dist;
            candidates.clear();
            candidates.insert({x, y});
        }else if( dist == max_dist){
            candidates.insert({x, y});
        }else{
            continue;
        }
    }

    unordered_map<long long, long long> hightest_y;
    unordered_map<long long, long long> lowest_y;

    for(int i=0; i<N; ++i){
        long long x = p[i].first;
        long long y = p[i].second;
        if( hightest_y.count(x) > 0 && y < hightest_y[x] ) continue;
        hightest_y[x] = y;

        if( lowest_y.count(x) > 0 && y > lowest_y[x] ) continue;
        lowest_y[x] = y;
    }

    long long ans = 0;
    for(auto p : candidates){
        long long cx = p.first;
        long long cy = p.second;
        for(auto hmp: hightest_y){
            long long x = hmp.first;
            long long y = hmp.second;
            ans = max( ans, abs(cx - x) + abs(cy - y) );
        }

        for(auto lmp: lowest_y){
            long long x = lmp.first;
            long long y = lmp.second;
            ans = max( ans, abs(cx - x) + abs(cy - y) );
        }
    }

    cout << ans << endl;

}
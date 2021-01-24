#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long f(vector<pair<long long, long long>> vec){
    long long n = vec.size();
    for(int i=0; i<n; ++i){
        vec[i].first = min(n, vec[i].first);
    }
    vector<vector<long long>> pos_sec(n+1);

    for(int i=0; i<n; ++i){
        pos_sec[vec[i].first].push_back(vec[i].second);
    }
    long long res = 0;
    priority_queue<long long> q;

    for(int i=n; i>=1; --i){
        for(auto x : pos_sec[i]){
            q.push(x);
        }
        if(q.size() > 0){
            res += q.top();
            q.pop();
        }
    }

    return res;

}


long long solve(){
    int n; cin >> n;

    //first: position, second: score;
    vector<pair<long long, long long>> camels_left;
    vector<pair<long long, long long>> camels_right;

    long long ans = 0;
    for(int i=1; i<=n; ++i){
        long long k, l, r; 
        cin >> k >> l >> r;
        long long small = min(l, r);
        ans += small;
        long long score;
        if(l - small > 0 ){
            score = l - small;
            camels_left.push_back({k, score});
        }else{
            score = r - small;
            camels_right.push_back({n-k, score});
        }
    }
    ans += f(camels_left);
    ans += f(camels_right);

    return ans;
}


int main(){
    int t; cin >> t;
    for(int i=0; i<t; ++i){
        cout << solve() << endl;
    }

}
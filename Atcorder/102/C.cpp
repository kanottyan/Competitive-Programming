#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> a(N);

    for(int i=0; i < N; ++i){
        cin >> a[i];
    }

    map<long long, long long> delta_cnt;
    vector<long long> delta_array(N);

    for(int i=1; i<=N; ++i){
        long long delta = a[i-1] - i;
        delta_array[i-1] = a[i-1] - i;
        if(delta_cnt.count(delta)){
            delta_cnt[delta]++;
        }else{
            delta_cnt[delta] = 1;
        }
    }

    pair<long long, long long> mx = {0, 0};

    for( auto delta : delta_cnt ){
        if(mx.second < delta.second){
            mx = delta;
        }
    }
    long long ans = 0;


    // if(mx.second == 1){
        sort(delta_array.begin(), delta_array.end());
        long long mid_idx = delta_array.size()/2;
        long long mid = delta_array[mid_idx];

        for(auto delta : delta_cnt){
            ans += abs(delta.first - mid) * delta.second;
        }

    // }else{

    //     for(auto delta : delta_cnt){
    //         ans += abs(delta.first - mx.first) * delta.second;
    //     }
    // }

    cout << ans << endl;

}
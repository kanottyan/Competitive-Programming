#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
long long LMAX = __LONG_LONG_MAX__;

int main(){
    long long N; cin >> N;
    long long M; cin >> M;
    long long end_pos = N-1;

    vector<long long> A(M);
    for(int i=0; i<M; ++i){
        cin >> A[i];
        A[i]--;
    }

    sort(A.begin(), A.end());

    long long prev = 0;
    long long min_dist = LMAX;
    vector<long long> intervals;

    long long interval;
    for(int i=0; i<M; ++i){
        if(i == 0){
            interval = A[i] - prev;
            prev = A[i];
            if(interval == 0){
                continue;
            }else{
                intervals.push_back(interval);
            }
        }else{
            interval = A[i] - prev - 1;
            prev = A[i];
            if(interval == 0){
                continue;
            }else{
                intervals.push_back(interval);
            }
        }
        min_dist = min(min_dist, interval);
    }

    if(intervals.size() == 0 && M == 0) end_pos += 1;
    if(prev != end_pos){
        interval = end_pos - prev;
        min_dist = min(min_dist, interval);;
        intervals.push_back(interval);
    }


    long long res = 0;
    for(int i=0; i<intervals.size(); ++i){
        res += intervals[i] / min_dist;
        if(intervals[i] % min_dist != 0) res++;
    }

    cout << res << endl;
    return 0;
}
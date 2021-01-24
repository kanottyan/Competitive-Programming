#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> a(N+1);
    for(int i=0; i<=N; ++i){
        cin >> a[i];
    }

    //from back to top; calculate available nodes
    vector<pair<long long, long long> > available_range(N+1);
    for(int i=N; i>=0; --i){
            long long mmin;
            long long mmax; 
        if( i == N){
            mmin = a[i];
            mmax = a[i]; 

        }else{
            mmin = (available_range[i+1].first + 1 )/2;
            if(mmin == 0) mmin = 1;
            mmin += a[i];
            mmax = available_range[i+1].second + a[i];
        }
        available_range[i].first = mmin;
        available_range[i].second = mmax;
    }

    //check if the depth array is avalable or not. if root[0] contains 1, then it should be fine.
    if(available_range[0].first == 1 || available_range[0].second < 1){
        long long res = 1;
        // long long pre_available_edge = 1;
        // long long curr_available_edge = 1;
        long long next_available_edge = 1;
        for(long long i=1; i<available_range.size(); ++i){           
            next_available_edge = next_available_edge * 2;
            next_available_edge = min(next_available_edge, available_range[i].second);
            res += next_available_edge;
            next_available_edge -= a[i];
            // curr_available_edge = min( pre_available_edge * 2, available_range[i].second);
            // res += curr_available_edge;
            // pre_available_edge = curr_available_edge;
            // pre_available_edge -= a[i];
        }
        cout << res << endl;
    }else{
        cout << -1 << endl;
    }

}
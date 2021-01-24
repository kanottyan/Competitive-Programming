#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K, N;
    cin >> K >> N;
    vector<long long> l;
    vector<long long> delta_l;

    for(int i=0; i<N; ++i){
        long long ai;
        cin >> ai;
        l.push_back(ai);
    }

    long long MAX = 0;
    for(int i=0; i<l.size()-1; ++i){
        long long gap = l[i+1] - l[i];
        if(gap > 0){
            MAX = max(MAX, gap);
            delta_l.push_back(gap);
        }
    }
    
    // delta of N and 0
    delta_l.push_back( abs( (K - l[N-1]) + l[0]) );
    MAX = max(MAX, abs( (K - l[N-1]) + l[0]) );


    long long ans = 0;
    for(int i=0; i<N; ++i){
        ans += delta_l[i];
    }
    ans -= MAX;

    cout << ans << endl;
}

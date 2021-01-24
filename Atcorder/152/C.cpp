#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    int N; cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; ++i) cin >> P[i];

    int ans = 1;
    int left = 0, right = 0;

    int lowest_h = P[0];

    for(int i=1; i<N; ++i){
        if( P[i] <= lowest_h){
            ans += 1;
            lowest_h = P[i];
        }
    }

    // for(int i=1; i<N; ++i){
    //     if( curr_h > P[i] ){
    //         right++;
    //     }else{
    //         ans += (right - left);
    //         left = right;
    //     }

    //     curr_h = P[i];
    // }
    // if(right - left != 0) ans += (right - left);

    cout << ans << endl;

    return 0;
}
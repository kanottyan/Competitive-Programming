#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

long long span[200010];
long long cumsum[200010];

// long long span[20];
// long long cumsum[20];

int main(){
    int N, W;
    cin >> N >> W;

    for(int i=0; i<N; ++i){
        long long s, t, p;
        cin >> s >> t >> p;

        span[s] += p;
        span[t] -= p;
    }

    for(int i=0; i<200010; ++i){
        span[i+1] += span[i];
    }

    string ans = "Yes";
    for(int i=0; i<200010; ++i){
        if(span[i] > W ) ans = "No";
    }

    cout << ans << endl;
}


// int main(){
//     int N, W; 
//     cin >> N >> W;

//     for(int i=0; i<N; ++i){
//         long long s, t, p;
//         cin >> s >> t >> p;
//         span[s] += p;
//         span[t] -= p;
//     }

//     cumsum[0] = span[0];

//     string ans = "Yes";
//     if(cumsum[0] > W) ans = "No";

//     for(int i=1; i<N; ++i){
//         cumsum[i] = cumsum[i-1];
//         cumsum[i] += span[i];
//         if(cumsum[i] > W) ans = "No";
//     }

//     cout << ans << endl;
//     return 0;
// }
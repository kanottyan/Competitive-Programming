#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N, K; cin >> N >> K;
    vector<int> towns;

    for(int i=0; i<N-1; ++i){
        towns.push_back(i+1);
    }

    vector<vector<long long>> dist(N, vector<long long>(N));

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> dist[i][j];
        }
    }

    int cnt = 0;

    do {
        long long k = 0;
        // 1-->t0
        k+= dist[0][towns[0]];
        //for
        for(int i=0; i<towns.size()-1; ++i){
            k += dist[towns[i]][towns[i+1]];
        }
        //tend -->1
        k += dist[towns[towns.size()-1]][0];
        if(k == K) cnt++;

    }while (next_permutation(towns.begin(), towns.end()));

    cout << cnt << endl;

    return 0;
}
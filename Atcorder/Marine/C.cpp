#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i=0; i<N; ++i){
        cin >> a[i];
    }

    // int trial_num;

    for(int n=0; n< K; ++n){
        vector<int> delta(N, 0);
    //     for(int i=0; i<N; ++i){
    //         int power = a[i];

    //         int MIN = max(0, i - power);
    //         int MAX = min( N-1, i + power);

    //         if(power > 0){
    //             for(int j=MIN; j<i; ++j){
    //                 delta[j]++;
    //             }

    //             for(int j=i+1; j<=MAX; ++j){
    //                 delta[j]++;
    //             }
    //         }
    //     }
    //     for(int i=0; i<N; ++i){
    //         delta[i]++;
    //     }
    //     swap(a, delta);

    // 　累積和
    for(int i=0; i<N; ++i){
        int power = a[i];
        int l  = max(0, i- power);
        int r = min(N-1, i+power);

        delta[l]++;
        if(r+1 < N) delta[r+1]--;
    }

    for(int i=1; i<N; i++){
        delta[i] += delta[i-1];
    }

    if( a == delta) break;
    else swap(a, delta);
    }

    for(int i=0; i<N; ++i){
        cout << a[i] << " ";
    }


    return 0;
}
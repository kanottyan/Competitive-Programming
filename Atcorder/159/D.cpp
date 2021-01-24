#include <iostream>
#include <vector>

using namespace std;

long long ball_counter[200100];
long long ball_selection[200100];


int main(){
    long long N;
    cin >> N;
    vector<long long> a(N);
    for(long long i=0; i<N; ++i) cin >> a[i];

    for(long long i=0; i<N; ++i){
        ball_counter[a[i]]++;
    }

    for(long long i=0; i<200100; ++i){
        if(ball_counter[i] > 1){
            ball_selection[i] = ball_counter[i] * (ball_counter[i] - 1 );
            ball_selection[i] /= 2;
        }
    }

    long long total = 0;
    for(long long i=0; i<200100; ++i){
        total += ball_selection[i];
    }


    for(int i=0; i<N; ++i){
        long long ans;
        ans = total - (ball_counter[a[i]] - 1);
        cout << ans << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const long long INF = 1LL << 61;

int main(){
    int N;
    cin >> N;
    vector<int> ppl(N);
    for(int i=0; i<N; ++i){
        cin >> ppl[i];
    }

    long long ans = INF;
    for(int i=0; i<=100; ++i){
        long long tmp = 0;
        for(auto p :ppl){
            tmp += abs(p - i) * abs(p - i);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
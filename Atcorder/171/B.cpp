#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<long long> p(N);
    for(int i=0; i<N; ++i){
        long long n;
        cin >> n;
        p[i] = n;
    }
    sort(p.begin(), p.end());

    long long ans = 0;
    for(int i=0; i<K; ++i){
        ans += p[i];
    }

    cout << ans << endl;
}
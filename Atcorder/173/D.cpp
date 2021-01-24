#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());

    // priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > q;

    long long ans = A[0];
    // q.push({min(A[0], A[1]), max(A[0], A[1])});
    vector<int> life(N);
    for(int i=0; i<N; ++i){
        life[i] = 2;
    }

    int idx = 1;
    for(int i=2; i<N; ++i){
        if(life[idx] >0){
            ans += A[idx];
            life[idx]--;
        }else{
            idx++;
            ans += A[idx];
            life[idx]--;
        }
    }

    cout << ans << endl;
}
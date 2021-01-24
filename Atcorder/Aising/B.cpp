#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int N; cin >> N;
    vector<int> a(N+1);

    for(int i=1; i<=N; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for(int i=1; i<=N; ++i){
        if(i % 2 == 1 && a[i] % 2 == 1) ans++;
    }

    cout << ans << endl;
}
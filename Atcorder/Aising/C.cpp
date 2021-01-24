#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int cnt[100000];

int main(){
    int N; cin >> N;

    for(int i = 1; i<= 100; ++i){
        for(int j=1; j<= 100; ++j){
            for(int k=1; k<=100; ++k){
                int ans = i*i + j*j + k*k;
                ans += i*j + j*k + i*k;
//                cout << i << " " << j << " " << k << " :" << ans << endl;
                cnt[ans]++;
            }
        }
    }


    for(int i=1; i<=N; ++i){
        cout << cnt[i] << endl;
    }
}
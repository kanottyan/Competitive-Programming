#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

const long long INF = 1LL << 61;

int main(){
    long long N, K; cin >> N >> K;

    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    // binary seach : 長さx以下にできるか？を計算
    long long ok = INF;
    long long ng = 0;

    while(ok - ng > 1){
        long long tmpK = K;
        long long mid = (ok + ng)/2;

        for(int i=0; i<N; ++i){
            if(mid < A[i]){
                tmpK -= A[i]/mid;
            }
        }

        if(tmpK <0 ){
            ng = mid;
        }else{
            ok = mid;
        }
    }

    cout << ok << endl;

    // multiset<long long, greater<long long>> s;

    // for(int i=0; i<N; ++i){
    //     long long A;
    //     cin >> A;
    //     s.insert(A);
    // }

    // for(int i=0; i<K; ++i){
    //     auto it = s.begin();
    //     long long first = *it;
    //     auto ni = next(it);
    //     long long second = *ni;
        
    // cout << "test" << endl;

    // }

}
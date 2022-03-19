#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N; ++i) cin >> B[i];

    set<int> s;
    for(int i=0; i<N; ++i) s.insert(A[i]);

    int ans1 = 0;
    int ans2 = 0;

    for(int i=0; i<N; ++i){
        if(A[i] == B[i]){
            ans1++;
            s.erase(B[i]);
        }else if(s.count(B[i]) > 0 ){
            ans2++;
            s.erase(B[i]);
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;


    return 0;
}
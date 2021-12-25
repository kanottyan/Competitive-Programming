#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint=modint998244353;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    reverse(A.begin(), A.end());

    mint tot = mint(2).pow(N-1);
    
    map<int, mint> m;
    for(int i=0; i<10; ++i) m[i] = 0;
    m[A.back()] = tot;
    A.pop_back();


    
    while(!A.empty()){
        map<int, mint> nm;
        for(int i=0; i<10; ++i) nm[i] = 0;
        
        int n = A.back();
        A.pop_back();

        for(int i=0; i<10; ++i){
            if(m[i] == 0) continue;

            int res1 = (i+n)%10;
            int res2 = (i*n)%10;

            nm[res1] += m[i]/2;
            nm[res2] += m[i]/2;
        }
        swap(nm, m);
    }

    for(auto p: m){
        cout << p.second.val() << endl;
    }

    return 0;
}
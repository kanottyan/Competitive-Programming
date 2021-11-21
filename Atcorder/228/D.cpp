#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
long long N = 1048576; // 1<<20;

vector<long long> to;

int update_to(long long from){
    if(to[from] == -1){
        return to[from] = from;
    }
    return to[from] = update_to((to[from]+1)%N);
}

int main(){
    int Q; cin >> Q;
    vector<long long> A(1LL<<20, -1);
    to.assign(N, -1);
    
    for(int i=0; i<Q; ++i){
        long long t, x; cin >> t >> x;
        if(t == 1){
            int dest = update_to(x%N);
            A[dest] = x;
        }else{
            cout << A[x%N] << endl;
        }
    }

    return 0;
}
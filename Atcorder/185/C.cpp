#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

set<long long> s{2,3,4,5,6,7,8,9,10,11};

long long fact(long long start, long long n){
    long long res = 1;
    for(long long i=start; i<=n; ++i){
        res = res * i;
        for(int i=2; i<11; ++i){
            if( res%i == 0 && s.count(i) > 0 ){
                res /= i;
                s.erase(i);
            }
        }
    }
    return res;
}

int main(){
    long long L; cin >> L;
    long long tmp = L-11;
    long long res = fact(tmp, L-1);

    for(long long elem : s){
        res /= elem;
    }

    cout << res << endl;
}
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<pair<long long, long long>> PrimeFac(long long N){
    vector<pair<long long, long long>> res;

    for(long long i =2; i * i <= N; ++i){
        if(N % i != 0) continue;

        long long ex = 0;
        while( N%i == 0){
            ex++;
            N /= i;
        }
        res.push_back({i,ex});
    }

    if(N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    long long A, B; cin >> A >> B;
    const auto& peA = PrimeFac(A);
    const auto& peB = PrimeFac(B);

    set<long long> s;


    for(auto pe: peA){
        s.emplace(pe.first);
    }

    long long ans = 0;
    for(auto pe: peB){
        if( s.count(pe.first) > 0) ans++;
    }

    cout << ans+1 << endl;

}
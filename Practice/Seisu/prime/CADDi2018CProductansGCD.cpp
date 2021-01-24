//https://atcoder.jp/contests/caddi2018/tasks/caddi2018_a

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<pair<long long, long long> > prime_fac(long long N){
    vector<pair<long long, long long> > res;
    for(long long i=2; i*i<=N; ++i){
        if(N%i != 0)continue;

        long long ex = 0;
        while(N%i ==0){
            ex++;
            N /= i;
        }

        res.push_back({i, ex});
    }

    if(N != 1){
        res.push_back({N, 1});
    }

    return res;
} 

int main(){

    long long N, P;
    cin >> N >> P;

    const auto& res = prime_fac(P);
    long long ans = 1;

    for(int i=0; i<res.size(); ++i){
        if(res[i].second >= N){
            long long tmp1 = (res[i].first);
            long long tmp2 = (res[i].second)/N;
            ans *= pow(tmp1, tmp2); 
        }
    }

    cout << ans << endl;

}
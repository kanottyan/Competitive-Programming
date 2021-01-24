#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

//約数列挙
vector<long long> enum_devisors(long long N){
    vector<long long> res;
    for(long long i=1; i*i<=N; ++i){
        if(N%i != 0)continue;
        res.push_back(i);
        if(N/i != i) res.push_back(N/i);
    }
    //sort(res.begin(), res.end());
    return res;
}

int main(){
    long long S, P;
    cin >> S >> P;

    vector<long long> res = enum_devisors(P);
    string ans = "No";
    for(long long num : res){
        if( num + P/num == S) ans = "Yes";
    }

    cout << ans << endl;

}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint fact(mint N){
    if(N.val() > 1) return N * fact(N-1);
    return mint(1);
}


int main(){

    int N; cin >> N;
    mint ans = 0;

    pair<map<int, int>, map<int, int>> p;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        if(a%2 == 0){
            p.second[a]++;
        }else{
            p.first[a]++;
        }
    }
    int even_num = 0;
    for(auto m : p.second){
        even_num += m.second;
    }

    ans = ans + fact(mint(even_num));

    



    cout << ans.val() << endl;


}
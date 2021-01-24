#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M;
    cin >> N >> M;
    dsu d(N);

    for(int i=0; i<M; ++i){
        int A, B;
        cin >> A >> B;
        A--; B--;
        d.merge(A, B);
    }

    auto ans = d.groups();
    cout << ans.size()-1 << endl;
}
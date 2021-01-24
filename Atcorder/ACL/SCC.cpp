#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

int main(){
    int N, M;
    cin >> N >> M;
    scc_graph sg(N);

    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        sg.add_edge(a, b);
    }
    auto ans = sg.scc();

    cout << ans.size()<< endl;

    for(auto group : ans){
        cout << group.size() << " ";
        for(auto node : group){
            cout << node << " ";
        }
        cout << endl;
    }
}
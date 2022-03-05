#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N, M; cin >> N >> M;

    multiset<int> A;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        A.insert(a);
    }

    bool flag = true;
    for(int i=0; i<M; ++i){
        int b; cin >> b;
        if(A.count(b) > 0){
            A.erase( A.find(b));
        }else{
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
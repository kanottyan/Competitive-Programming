#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    string A, B; cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int keta = max(A.size(), B.size());

    bool flag = false;
    for(int i=0; i<keta; ++i ){
        int a = A[i] - '0';
        int b = B[i] - '0';
        if(a + b >= 10) flag = true;
    }

    if(flag){
        cout << "Hard" << endl;
    }else{
        cout << "Easy" << endl;
    }

    return 0;
}
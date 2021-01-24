#include <bits/stdc++.h>
#include <atcoder/all>


using namespace std;
using namespace atcoder;

int main(){

    int N; cin >> N;
    vector<long long> X(N);
    for(int i=0; i<N; ++i){
        cin >> X[i];
    }

    long long man =0;
    double yu = 0.0;
    long long che = 0;
    long long tmp = 0;

    for(int i=0; i<N; ++i){
        man += abs((long long)X[i]);
        che = max(che, (long long)abs(X[i]));
        tmp += (X[i] * X[i]);
    }
    yu = sqrt((double)tmp);

    cout << man << endl;
    cout << fixed << setprecision(15) << yu << endl;
    cout << che << endl;
}
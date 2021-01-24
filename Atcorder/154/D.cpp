#include <bits/stdc++.h>
using namespace std;



int main(){
    int N, K; cin >> N >> K;
    //期待値
    vector<double> E(N);

    //数値
    vector<double> P(N);

    for(int i=0; i<N; ++i){
        cin >> P[i];
    }

    //期待値計算
    for(int i=0; i<N; ++i){
        if(P[i] == 1){
            E[i] = 1.0;
        }else{
            E[i] = ((P[i]*(2.0 * 1.0 + (P[i] - 1.0)))/2.0)/P[i];
        }
    }

    double ans = 0.0;
    double tmp = 0.0;

    for(int i=0; i<K; ++i){
        tmp += E[i];
    }

    ans = tmp;

    for(int i=K; i<N; ++i ){
        tmp -= E[i-K];
        tmp += E[i]; 
        ans = max(ans, tmp);
    }


    cout << fixed << setprecision(10) << ans << endl;
}
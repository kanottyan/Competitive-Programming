#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    long long sum = 0;

    for(int i=0; i<N; ++i){
        long long A, B;
        cin >> A >> B;

        long long num = B-A+1;

        long long tmp = (A+B)*num/2;
        sum += tmp;
    }
    cout << sum << endl;

}
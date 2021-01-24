#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    long long N; cin >> N;
    long long A, B; cin >> A >> B;

    long long times = N/(A+B);
    long long res = N%(A+B);

    long long ans;
    if(res > A){
        ans = A * (times + 1);
    }else{
        ans = A*times + res;
    }

    
    cout << ans << endl;
}
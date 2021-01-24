#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//const long long MAX = 100;
const long long MAX = 10000010;
long long cumsum[MAX] ;


int main(){
    long long N;
    cin >> N;

    for(long long i=1; i< MAX; ++i){
        cumsum[i] = 1;
    }

    for(long long i=2; i<=10000010; ++i){
        for(long long j=1; j*i< MAX; ++j ){
            cumsum[i*j]++;
        }
    }

    long long ans = 0;

    for(long long i = 1; i <=N; ++i){
        ans += cumsum[i] * i;
    }

    cout << ans << endl;
}
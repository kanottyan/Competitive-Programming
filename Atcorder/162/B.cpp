#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6+10;

long long fac[MAX];

int main(){
    int N; cin >> N ;

    long long ans = 0;
    for(int i = 1; i <= N; ++i ){
        if( i % 3 == 0 || i % 5 == 0) continue;
        ans += i;
    }

    cout << ans << endl;
}
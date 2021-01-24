#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    long long ans = 0;

    while(N >= 500){
        ans += 1000;
        N -= 500;
    }

    while(N >= 5){
        ans += 5;
        N -= 5;
    }

    cout << ans << endl;

}
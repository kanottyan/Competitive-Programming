#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int ans;

    if(N <=1 && M <=1 ) ans = 0;
    ans = N * (N -1)/2 + M * (M-1)/2;


    cout << ans << endl;
}
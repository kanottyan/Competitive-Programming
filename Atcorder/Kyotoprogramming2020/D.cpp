#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;

    if( N == 2 || N%2 == 1){
        cout << "impossible" << endl;
        return 0;
    }

    int min = 1;
    int max = 2 * N -1;

    int mid = (min + max)/2;

    cout << N/2 << endl;

    int left = min;
    int right = max;

    while( right > left){
        cout << 2 << " ";
        cout << left << " " << right << endl;
        left += 2;
        right -= 2;
    }

}
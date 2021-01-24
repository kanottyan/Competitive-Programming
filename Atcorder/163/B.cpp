#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M);

    int sum = 0;
    for(int i=0; i<M; ++i) cin >> a[i];

    for(int i=0; i<M; ++i){
        sum += a[i];
    }
    int res = N -sum;
    if(res < 0) res = -1;

    cout << res << endl;
}
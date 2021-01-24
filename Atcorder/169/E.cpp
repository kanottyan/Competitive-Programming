#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2
// 158260522 877914575
// 24979445 602436426
// 1297111035

int main(){
    int N;  cin >> N;

    vector<long long> min_array(N);
    vector<long long> max_array(N);

    for(int i=0; i<N; ++i){
        long long A, B; cin >> A >> B;
        min_array[i] = A;
        max_array[i] = B;
    }

    double max = 1e9;
    double min = 1;
    double res = 1;

    sort(min_array.begin(), min_array.end());
    sort(max_array.begin(), max_array.end());
    if(min_array.size()%2 == 1){
        min = min_array[N/2];
        max = max_array[N/2];
        res = max - min +1;
    }else{
        min = (min_array[N/2] + min_array[N/2-1])/2.0;
        max = (max_array[N/2] + max_array[N/2-1])/2.0;
        res = (max - min)*2.0 +1.0;
    }

    cout << (long long)res << endl;
}
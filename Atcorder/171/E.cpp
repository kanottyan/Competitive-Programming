#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);

    for(int i=0; i<N; ++i){
        cin >> a[i];
    }

    long long tmp = a[0];
    for(int i=1; i<N; ++i){
        tmp = tmp ^ a[i];
    }
    
    for(int i=0; i<N; ++i){
        long long ans = tmp ^ a[i];
        cout << ans << " "; 
    }

    cout << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);

    for(int i=0; i<N; ++i) cin >> a[i];

    int s = 0;
    for(int i=0; i < N; ++i){
        s += a[i];
    }

    int candidate = 0;
    for(int i=0; i< N; ++i){
        if( s % (4*M) == 0 ){
            if( a[i] >= s/(4*M) ) candidate++;
        }else{
            if( a[i] > s/(4*M) ) candidate++;
        }
    }

    if(candidate >= M){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
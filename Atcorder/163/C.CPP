#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N,0);
    for(int i=1; i<N; ++i){
        int num;
        cin >> num;
        --num;
        a[num] += 1;
    } 

    for(int i=0; i<N; ++i){
        cout << a[i] << endl;
    }    
}
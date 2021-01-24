#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a(5);

    for(int i=0; i<5; ++i){
        cin >> a[i];
    }

    int ans = 0;
    for(int i=0; i<5; ++i){
        if(a[i] == 0){
            ans = i+1;
        }
    }

    cout << ans << endl;
}
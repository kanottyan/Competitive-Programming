#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h1, m1, h2, m2, K;
    cin >> h1 >> m1 >> h2 >> m2 >> K;

    int interval = (h2*60 + m2) - (h1*60 + m1);
    int ans;
    if( interval - K <= 0 ){
        ans = 0;
    }else{
        ans = interval - K;
    }

    cout << ans << endl;
}
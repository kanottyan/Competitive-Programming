//https://atcoder.jp/contests/abc014/tasks/abc014_3
//https://freestylewiki.xyz/fswiki/wiki.cgi?page=imos法・累積和

#include <iostream>
#include <vector>

using namespace std;
const int COLORS = 1000100;

int cumsum[COLORS];

int main(){
    int n;
    cin >> n;


    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;

        cumsum[a]++;
        cumsum[b+1]--;
    }

    int ans = cumsum[0];
    for(int i=1; i<=COLORS; ++i){
        cumsum[i] += cumsum[i-1];
        ans = max(ans, cumsum[i]);
    }

    cout << ans << endl;
}
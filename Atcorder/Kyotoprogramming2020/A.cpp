#include <bits/stdc++.h>

using namespace std;

long long memo[100][100] = {-1};

void rec( )

int main(){
    int N;
    cin >> N;

    int x, y;
    cin >> x >> y;
    long long ans = 0;

    for(int i=1; i<N; ++i){
        int nx, ny;
        cin >>nx >> ny;
        ans += abs(x - nx) + abs(y - ny);
        x = nx; 
        y = ny;
    }

    long long ans = 0


    cout << ans << endl;

}
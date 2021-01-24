#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    
    for(int i=0; i<n; ++i) cin >> x[i] >> y[i];

    int s_dash = n;
    int t_dash = n+1;

    double ok = 0;
    double ng = 200;

    for(int trial=0; trial<85; ++trial){
        double mid = (ok+ng)/2;
        dsu d(n+2);

        //直線とマージ
        for(int i=0; i<n; ++i){
            if( y[i] + mid > 100 ) d.merge(i, s_dash);
            if( y[i] - mid < -100 ) d.merge(i, t_dash);
        }

        //点でマージ
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i ==j) continue;
                int dx = x[j] - x[i];
                int dy = y[j] - y[i];
                int dist = dx*dx+dy*dy;

                if(dist < mid*mid)d.merge(i, j);
            }
        }

        if(d.same(s_dash, t_dash)) ng = mid; else ok = mid;
    }

    cout << fixed<< setprecision(10) << ok/2 << endl;

}
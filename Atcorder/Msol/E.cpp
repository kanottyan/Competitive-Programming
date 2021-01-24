#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

const long long INF = 1e16;

//取り出してxとpの組(青い点)の列に対して、kを全部試す(k個黒い点をおいたときの最小の値)
vector<long long> calc(vector<pair<int, int>> a){
    int n = a.size();
    vector<long long> res(n+1, INF);
    //黒点の置き方を全部試す
    for(int s=0; s< (1<<n); ++s){
        //ゼロには最初から黒点がある。
        vector<int> p(1, 0);

        //i桁立ってたらpに入れる
        for(int i=0; i<n; ++i){
            if(s>>i &1){
                p.push_back(a[i].first);
            }
        }
        long long now = 0;
        //それぞれの青点について最も近い黒点を探す
        for(int i=0; i<n; ++i){
            int m = INF;
            for(int j=0; j<p.size(); ++j){
                m = min(m, abs(p[j]-a[i].first));
            }
            now += (long long)m*a[i].second;
        }
        int b = p.size()-1;
        res[b] = min(res[b], now);
    }
    return res;
}


int main(){
    int n; cin >> n;
    vector<int> X(n), Y(n), P(n);

    for(int i=0; i<n; ++i){
        cin >> X[i] >> Y[i] >> P[i];
    }
    vector<long long> ans(n+1, INF);
    for(int s=0; s< (1<<n); ++s){
        vector<pair<int, int>> ax, ay;
        for(int i=0; i<n; ++i){
            //xにするかを決め打つ
            if(s>>i & 1){
                ax.emplace_back(X[i], P[i]);
            }else{
            //yに決め打つ
                ay.emplace_back(Y[i], P[i]);
            }
        }
        //xにすると決めうったときの最小値
        vector<long long> dx = calc(ax);
        //yにすると決めうったときの最小値
        vector<long long> dy = calc(ay);
        //dxとdyをまとめる
        for(int i=0; i<dx.size(); ++i){
            for(int j=0; j<dy.size(); ++j){
                ans[i+j] = min( ans[i+j], dx[i] + dy[j] );
            }
        }
    }

    for(int i=0; i<n+1; ++i){
        cout << ans[i] << endl;
    }

} 
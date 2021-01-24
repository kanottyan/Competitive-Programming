#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const long long INF = 1e18;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    --si; --sj; --ti; --tj;

    vector<string> g(h);
    for(int i=0; i<h; ++i) cin >> g[i];

    auto toId = [&](int i, int j, int v){
        return (i*w+j)*4 +v;
    };

    auto modCeil = [&](long long x){
        //kで割って切り上げ
        auto ans = ((x+k-1)/k)*k;
        return ans;
    };

    vector<long long> dist(h*w*4, INF);

    priority_queue< pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > >q;
    auto push = [&](int i, int j, int v, long long x){
        int id = toId(i, j, v);
        //もし既存の値のが小さかったら更新しない
        if(dist[id] <= x)return;
        dist[id] = x;
        q.emplace(x, id);
    };

    //init
    for( int v=0; v<4; ++v){
        push(si, sj, v, 0);
    }

    //djikstra
    while(!q.empty()){
        long long d = q.top().first;
        int id = q.top().second;
        q.pop();
        //更新して一致してない場合は飛ばす
        if(dist[id] != d){
            continue;
        }

        //        
        int i = id/4/w;
        int j = id/4%w;
        int v = id%4;
        
        //向きを変える
        for(int nv = 0; nv<4; ++nv){
            push(i, j, nv, modCeil(d));
        }

        //同じ向きに進む
        int ni = i+di[v];
        int nj = j+dj[v];
        //範囲内かつ
        if( 0 <= ni && ni <h && 0<= nj && nj < w){
            //障害物じゃない
            if(g[ni][nj] == '.'){
                push(ni, nj, v, d+1);
            }
        }
    }

    long long ans = INF;
    for(int v=0; v<4; ++v){
        ans = min(ans, dist[toId(ti,tj,v)]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        ans = modCeil(ans)/k;
        cout << ans << endl;
    }


}
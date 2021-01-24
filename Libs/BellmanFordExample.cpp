//https://atcoder.jp/contests/abc061/tasks/abc061_d
#include <vector>
#include <iostream>
#include <climits>

struct Edge{
    long long from;
    long long to;
    long long cost;
};

using namespace std;
using Edges = vector<Edge>;
const long long INF = (1LL << 63) -1 ;
pair<bool, vector<vector<long long> > > bellman_ford(long long begin_idx, long long  N, const Edges& Es){
    //それぞれの頂点へ最短経路距離を保存する配列
    //始点0 ,その他はINF
    //どの頂点がサイクルになっちゃって更新されているのかも1idxで記録
    vector<vector<long long>>  dist_and_updatedflag(N, vector<long long>(2));

    for(int i=0; i<N; ++i){
        dist_and_updatedflag[i][0] = INF;
        dist_and_updatedflag[i][1] = false;
    }

    dist_and_updatedflag[0][0] = 0;

    int cnt = 0;
    while(cnt < N){
        bool end = true;

        for(auto e: Es){
            if(dist_and_updatedflag[e.from][0] != INF && dist_and_updatedflag[e.from][0] + e.cost < dist_and_updatedflag[e.to][0] ){
                dist_and_updatedflag[e.to][0] = dist_and_updatedflag[e.from][0] + e.cost; 
                //一回でも更新したら,終わりではない
                end = false;
                //最後に更新された頂点を記録
                if(cnt == N -1){
                    dist_and_updatedflag[e.to][1] = true;
                }
            }
        }
        //更新がなかったらループ抜ける
        if(end) break;
        cnt++;
    }
    
    return {cnt == N, dist_and_updatedflag};
}

int main(){
    int N, M;
    cin >> N >> M;

    Edges edges(M);
    for(int i=0; i<M; ++i){
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = {a, b, -c};
    }

    const auto& dist = bellman_ford(0, N, edges);
    if(dist.first == true){
        if(dist.second[N-1][1] == true){
            cout << "inf" << endl;
        }else{
            cout << -dist.second[N-1][0] << endl;
        }
    } else{
        cout << -dist.second[N-1][0] << endl;
    }   
}
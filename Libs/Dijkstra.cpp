//https://atcoder.jp/contests/abc168/tasks/abc168_d

//usage:
//負の辺を含まない重み付きグラフの単一始点最短経路問題に対して使われます。

// priority_queue（優先度キュー）を用意し、始点の情報とそこへの最短距離（始点なら 0
//  ）をpushする。このとき、最短距離順で情報がソートされるようにする。
// キューが空になるまで、次の操作を繰り返す。
// キューの先頭要素（最短距離の一番小さいもの）を取り出す。
// もし、記録してある最短距離より取り出した要素に入っている距離情報のほうが大きければ、ここで打ち切って先頭要素を取り出す操作に戻る。
// そこから移動できる頂点を走査し、最短距離が更新できるものがあれば、距離を更新してからその頂点への距離、頂点の情報をキューにpushする。


//問題例
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const long long INF = (1LL <<31) -1 ;


// beging_idx: スタートの頂点のインデックス
// n頂点数
// graph: 隣接グラフとその重みなどを記録する配列。
vector<long long> dijkstra(long long begin_idx, long long n, const vector<vector< vector<long long> > >& graph)
{
    //最短経路としてどの頂点が確定済みかをチェックする配列
    vector<bool> confirmed(n, false);

    //それぞれの頂点へ最短経路距離を保存する配列
    //始点0 ,その他はINF
    vector<long long>  dist(n, INF); dist[begin_idx] = 0;
    //P確定済みの頂点の集合から伸びる辺を伝ってたどり着く頂点の始点からの距離を短い順に保存するPriority queue
    //要するにどこの頂点を付き捜索するのかを決める

    //昇順の場合はgreater
    //pairの比較は一つ目の要素→二つ目の要素の優先順位
    priority_queue< vector<long long>, 
                    vector<vector<long long > >, 
                    greater<vector<long long > > > que;

    //始点を入れる
    //今回 idx0が始点からそこまで行くのにかかる距離,idx1が頂点インデックス, 
    que.push({dist[begin_idx], begin_idx});

    //要素がすべて確定するまで頂点を小さい順方見ていく
    while(!que.empty()){
        vector<long long> cur_node = que.top();
        que.pop();

        //すでにその頂点への最短距離が確定済みの場合は飛ばす
        if(confirmed[cur_node[1]]) continue;

        confirmed[cur_node[1]] = true;

        //その確定済みの頂点から伸びる辺の情報をとってくる(参照の方が速い)、lは辺の本数
        //next_candidatesは頂点(idx1)と、その頂点にcurから行くのにかかるコスト(idx0)が入ってる
        const auto& next_candidates = graph[cur_node[1]];

        for(auto next_node : next_candidates){
            //確認済みなら更新しない
            if(confirmed[next_node[1]] == true) continue;
            //辺の重みを更新
            if( dist[cur_node[1]] + next_node[0] < dist[next_node[1]] ){
                dist[next_node[1]] = dist[cur_node[1]] + next_node[0];
                //更新した場合はその頂点が(確定済みでない頂点の中で)最短距離になる可能性があるのでmincandに挿入
                que.push( {dist[next_node[1]], next_node[1]} );
            }
        }
    }
    
    return dist;
}

int main(){
    int V, E, r;
    cin >> V >> E >> r;

    //隣接グラフとその重みをいれる
    // スタート点　: {重み、　行き先点}の構造
    vector<vector<vector<long long> > > graph(V);

    for(int i=0; i<E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({d, t});
        //graph[t].push_back({d, s});
    }

    vector<long long> ans = dijkstra(r, V, graph);

    for(long long i : ans){
        if(i == INF){
            cout << "INF" << endl;
        }else{
            cout << i << endl;
        }
    }
}
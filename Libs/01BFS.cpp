// https://betrue12.hateblo.jp/entry/2018/12/08/000020

// ノーコストの手段で移動する
// 何らかのコストや回数制限のある手段で移動する
// の2通りの移動方法が与えられているような問題は、01-BFSに帰着できることがあります。


// 両端キューの先頭から頂点 v を取り出す。
// 頂点 v から伸びる辺を用いて暫定最短距離を更新できる頂点がある場合、更新してその頂点を
// 0の辺を用いた場合は両端キューの先頭に加える。
// 1の辺を用いた場合は両端キューの末尾に加える。

#include <bits/stdc++.h>
using namespace std;

int main(){
    // 頂点数N, 始点の頂点番号s
    int N, s;
    // 隣接リスト
    // edges[i]の要素に(j, c)が含まれるとき、　iからjにコストcの辺が存在
    vector<vector<pair<int, int>>> edges(N);

    vector<int> dist(N, 1e9);
    dist[s] = 0;
    deque<int> que;
    que.push_back(s);

    while(que.size()){
        int i = que.front(); que.pop_front();
        for(auto [j, c] : edges[i]){
            int d = dist[i] + c;
            if( d < dist[j]){
                dist[j] = d;
                if(c){
                    que.push_back(j);
                }else{
                    que.push_front(j);
                }
            }
        }
    }
}
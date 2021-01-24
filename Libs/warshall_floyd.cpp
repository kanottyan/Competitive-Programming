//https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75

//頂点iから頂点jへの経路と、頂点kを経由した場合の経路とを比較してよりコストの合計が小さい方を配列に入れる

// void warshall_floyd(int n){
//     for(int k=0; k < n; ++k){  // 経由する頂点
//         for(int i=0; i<n; ++i){ // 始点
//             for(int j=0; j < n; ++j){  //// 終点
//                 d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//             }
//         }
//     }
// }

//問題例
//https://atcoder.jp/contests/abc073/tasks/abc073_d

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
const long long INF = (1LL << 29);

//dist table
long long graph[201][201];


int main(){
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> visit_towns(R);
    for(int i = 0 ; i < R; ++i){
        cin >> visit_towns[i];
        visit_towns[i]--;
    }


    //init
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i == j){
                graph[i][j] = 0;
            }else{
                graph[i][j] = INF;
            }
        }
    }


    for(int i=0; i<M; ++i){
        long long A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        graph[A][B] = min(C, graph[A][B]);
        graph[B][A] = min(C, graph[B][A]);
    }

    //warshall_floyd
    for(int k=0; k < N; ++k){  // 経由する頂点
        for(int i=0; i<N; ++i){ // 始点
            for(int j=0; j < N; ++j){  //// 終点
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    long long ans = INF;
    sort(visit_towns.begin(), visit_towns.end());
    do{
        long long tmp = 0;
        for(int i=0; i<visit_towns.size()-1; ++i){
            tmp += graph[visit_towns[i]][visit_towns[i+1]];
        }
        ans = min(ans, tmp);

    }while(next_permutation(visit_towns.begin(), visit_towns.end() ) );

    cout << ans << endl;
}
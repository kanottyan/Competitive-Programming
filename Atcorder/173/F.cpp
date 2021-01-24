//https://hcpc-hokudai.github.io/archive/dynamic_programming_rerooting.pdf
//https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#使用例


#include <iostream>
#include <vector>
#include <functional>
#include <stack>
using namespace std;
const long long INF = 1LL << 61;


//森の　Σ連結成分　＝　Σ頂点数　ー　Σ辺数
//Σ頂点数は、1の場合、2の場合と掛け算すれば求まる
//Σ辺数は両端の1.若い頂点番号よりも前の数と、2.大きい頂点番号後の番号数なら
//組み合わせなんでも良い

int main(){
    long long N;
    cin >> N;
    long long V =0, E=0;

    for(long long i=1; i<=N; ++i){
        V += i*((N+1)-i);
    }
    
    for(long long i=0; i<N-1; ++i){
        long long u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        E += u * (N+1-v);
    }

    long long ans = V - E;
    cout << ans << endl;
}
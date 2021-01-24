//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
//https://www.creativ.xyz/segment-tree-entrance-999/

#include<iostream>
#include<vector>

using namespace std;

#define INF 2147483647 // 2^31-1

vector<int> value; //ノードの値を持つ配列
int N; // 葉の数

void update(int i, int x){
    // i 番目の葉の値を x に変える
    i += N-1;
    value[i] = x;
    while(i > 0){
        i = (i-1)/2; //  ノード i の親ノードの番号に変える
        value[i] = min(value[i*2+1], value[i*2+2]);
    }
}

int query(int a, int b, int k, int l, int r){
     // [a, b) の区間に対するクエリについて
     // ノード k （区間 [l, r) 担当）が答える

     // 区間が被らない場合は INF を返す
    if(r <= a || b <= l) return INF;
    // ノード k の担当範囲がクエリ区間 [a, b)// に完全に含まれる
    if ( a <= l &&  r<=b ){
        return value[k];
    } else {
        int c1 = query(a, b, 2*k+1, l, (l+r)/2);
        int c2 = query(a, b, 2*k+2, (l+r)/2, r);
        return min(c1, c2);
    }
}

int main(){
    int n, q; // 数列のサイズとクエリの数
    cin >> n >> q;
    N=1;
    while(N < n) N *= 2; // 歯の数を計算(n以上の最小の2べき乗)

    value = vector<int>(2 * N -1, INF);

    for(int j=0; j<q; ++j){
        int c;
        cin >> c;
        if( c == 0){
            //update
            int i,x;
            cin >> i >> x;
            update(i, x);
        }else{
            //find
            int s, t;
            cin >> s >> t;
            cout << query(s, t+1, 0, 0, N) << endl;
        }
    }



}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint1000000007;

const int MX = 305;

//パスカルの三角形用の配列
mint c[MX][MX];
//dp[i][j] := i頂点を使った。j辺を追加したときの場合の数
mint dp[MX][MX];
//重複がないように数える定石は、残ってる番号のうち、
//最も番号が小さい番号の所属グループを決める。

//次に追加するグループの遷移は次元が2の場合、パスグラフになるか、
//サイクルになるかの二通りになる。
//パスグラフはk個頂点を追加すると　　i+= k; j+= k-1;
//サイクルグラフはk個頂点を追加すると　 i+=k, j+=k;
//パスグラフの場合はdp[i+k][j+k-1] += dp[i][j] *(k頂点のパスグラフのパターン) *頂点の選び方
//1-1.パスグラフの選び方(k>=1以上)
//矢印をつけて考慮すると、K!/2で1通り目は1になるのを注意
//1-2サイクルグラフ(k>=2以上)
//一つの頂点を除くとパスグラフになっている-->パスグラフを選んだときに両端をくっつけるのと同じ
//-->path[k-1]
//2頂点の選び方
//(n-i-1):= 残り頂点から1つの代表を覗いたもののうちK（K-1）頂点を選ぶ
//--> (n-i-1)C(k-1)
//これでDPして数え上げ可能

mint f(int n, int m, int l){
    mint res; 
    vector<mint> path(l+1);
    path[1] = 1;
    path[2] = 1;
    //パスの計算
    for(int i=3; i <= l; ++i){
        path[i] = path[i-1] * i;
    }

    vector<mint> cycle(l+1);
    //サイクルの計算１は存在しないので2以降
    for(int i=2; i <= l; ++i){
        cycle[i] = path[i-1];
    }

    //初期化
    for(int i=0; i<n+1; ++i){
        for(int j=0; j<m+1; ++j){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for(int i=0; i<n+1; ++i){
        for(int j=0; j<m+1; ++j){
            //パス
            for(int k=1; k<=l; ++k){
                int ni = i+k;
                int nj = j+k-1;
                if(ni > n) break;
                if(nj > m) break;
                dp[ni][nj] += dp[i][j] * c[n-i-1][k-1]*path[k];   
            }
            //サイクル
            for(int k=2; k<=l; ++k){
                int ni = i+k;
                int nj = j+k;
                if(ni > n) break;
                if(nj > m) break;
                dp[ni][nj] += dp[i][j] * c[n-i-1][k-1]*cycle[k];   
            }
        }
    }
    return dp[n][m];
}

int main(){
    //Combinationの前計算
    c[0][0] = 1;
    for(int i=0; i<MX-1; ++i){
        for(int j=0; j<MX-1; ++j){
            c[i+1][j] += c[i][j];
            c[i+1][j+1] += c[i][j]; 
        }
    }

    int n, m, l;
    cin >> n >> m >> l;
    //連結の最大がL. --> f(x)を全部x以下の連結とすると
    //maxL --> f(L) - f(L-1)
    mint ans = f(n, m, l);
    ans -= f(n, m, l-1);
    cout << ans.val() << endl;
    return 0;
}
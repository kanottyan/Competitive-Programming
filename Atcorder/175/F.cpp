#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct E {
    int to, co;
    E(int to=0, int co=0) : to(to), co(co){}
};

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int m;
    cin >> m;
    vector<string> s(m);
    vector<int> c(m);
    for(int i=0; i<m; ++i){
        cin >> s[i] >> c[i];
    }
    //逆もオッケー
    //これで0-mは正方向
    //m+1 - 2mは逆
    for(int i=0; i<m; ++i){
        s.push_back(rev(s[i]));
        c.push_back(c[i]);
    }

    //頂点を作る(n頂点)
    int n =1;
    //空文字列を0をする
    //各文字にidを割り当てる
    vector<vector<int>> id(m*2);
    for(int i=0; i<m*2; ++i){
        int l = s[i].size();
        id[i].resize(l);
        for(int j=0; j<l; ++j){
            id[i][j] = n++;
        }
    }

    //グラフを作る
    vector<vector<E>> g(n);
    //各suffixから遷移
    for(int i=0; i<m*2; ++i){
        int l = s[i].size();
        for(int j=0; j<l; ++j){
            //ここから遷移. j文字目以降が余ってる。
            //j=0は全部余ってるときはj=0;

            int v = id[i][j];
            for(int ni=0; ni<m*2; ++ni){
                // i/mすると前半なら0,後半なら1になる,
                //この２つが一緒なら何もしない
                if(i/m == ni/m) continue;
                //何文字で共通する?
                int nl = s[ni].size();
                int w = min(nl, l-j);
                //そもそも一致してないといけないのでその判定
                if(s[i].substr(j,w) != s[ni].substr(0, w)) continue;

                int u =0;
                //　うしろが余る条件
                if( nl > w){
                    u = id[ni][w];
                }else if(l > j+w){
                    //先頭が余る条件
                    u = id[i][j+w];
                }else{
                    //あまりなしの空文字
                    u = 0;
                }
                g[v].emplace_back(u, c[ni]);
            }
        }
    }

    //ダイクストラ
    vector<long long> dist(n, INF);
    //先頭が距離、後ろが頂点番号
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> q;
    auto push = [&](int v, long long x){
        if(dist[v] <= x) return;
        dist[v] = x;
        q.emplace(x, v);
    };

    for(int i=0; i<m; ++i){
        push(id[i][0], c[i]);
    }

    //内部のロジック
    while(!q.empty()){
        long long x = q.top().first;
        int v = q.top().second; 
        q.pop();
        if(dist[v] != x) continue;
        for(E e : g[v]){
            push(e.to, x+e.co);
        }
    }

    long long ans = dist[0];
    for(int i=0; i<m * 2; ++i){
        int l = s[i].size();
        for(int j=0; j<l; ++j){
            string t = s[i].substr(j);
            //回文ならオッケー
            if(t == rev(t)){
                ans = min(ans, dist[id[i][j]]);
            }
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
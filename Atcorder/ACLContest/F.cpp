#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;
using vm = vector<mint> ;

int main(){
    int n; cin >> n;
    int n2 = n*2;

    vector<int> a;
    {
        //グループのサイズに治す(分布作成)
        map<int, int> mp;
        for(int i=0; i<n2; ++i){
            int h; cin >> h;
            mp[h]++;
        }
        for(pair<int, int> p: mp) a.push_back(p.second);

    }
    //前計算
    //階乗
    vm f(n2+1);
    //階乗の逆元
    vm invf(n2+1);
    //二重階乗
    vm f2(n+1);
    {
        f[0] = 1;
        //階乗
        for(int i=0; i<n2; ++i){
            f[i+1] = f[i] *(i+1);
        }

        //階乗の逆元(注意割り算を２ｎ回してる！)
        // for(int i=0; i<n2+1; ++i){
        //     invf[i] = i/f[i];
        // }
        invf[n2] = 1/f[n2];
        for(int i =n2; i >= 1; --i){
            //こうすれば*の度にiが相殺される
            invf[i-1] = invf[i] * i;
        }

        //2重階乗(奇数のみ)
        f2[0] = 1;
        for(int i=0; i<n; ++i) f2[i+1] = f2[i] * (i*2+1);
    }


    //グループ数ｍ
    int m = a.size();
    vector<vm> d(m);
    for(int i=0; i<m; ++i){
        int na = a[i];
        //e:iグループ目の要素数で最大何個辺が取れる？
        int e = na/2;
        d[i] = vm(e+1);
        for(int j=0; j<e+1; ++j){
            d[i][j] = f[na]*invf[j*2]*invf[na-j*2]*f2[j];
        }
    }

    //FFTを２個ずつマージしていく
    while(d.size() > 1){
        vector<vm> pd;
        swap(d, pd);
        //pd -> dへ計算
        for(int i=0; i< pd.size(); i += 2){
            int j=i+1;
            //ペアがなかったらそのまま次のラウンドへ
            if( j >= pd.size() ){
                d.emplace_back(pd[i]);
                break;
            }
            
            //diとdjを叩き込む
            d.emplace_back(convolution(pd[i], pd[j]));
        }
    }

    mint ans;
    for(int i=0; i<d[0].size(); ++i){
        mint now = d[0][i] * f2[n-i];
        if(i%2 == 1) ans -= now;
        else ans += now;
    }

    cout << ans.val() << endl;
    return 0;
}
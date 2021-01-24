#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    //map[今] = 開始の最大値
    map<int,int> s;
    //答えを求める用
    multiset<int> vals;

    for(int i=0; i<w; ++i){
        s[i]  = i;
    }

    for(int i=0; i<w; ++i){
        vals.insert(0);
    }

    for(int i=0; i<h; ++i){
        int l, r;
        cin >> l >> r;
        --l;
        //init most right
        int mr = -1;

        //l以上で一番小さい値を返す
        auto it = s.lower_bound(l);
        //そこから最大の右の値までを消す。
        while(it != s.end() && it->first <= r){
            mr = max(mr, it->second);
            int x = it->first - it->second;
            //削除してインクメントされる
            s.erase(it++);
            vals.erase(vals.find(x));
        }
        //rが画面の端の場合は行けないので　w未満
        if(mr != -1 && r < w){
            //新たに得た値（合流したmrとr）を入れる
            vals.insert(r - mr);
            s[r] = mr;
        }

        int ans = -1;
        if(vals.size() > 0){
            //右移動と縦移動の回数
            ans = *vals.begin() + (i+1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
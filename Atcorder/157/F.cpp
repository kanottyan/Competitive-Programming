#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
bool equal(double a, double b){ return abs(a-b) < eps;}

//ベクトル演算
struct V{
    double x, y;
    V(double x=0, double y=0): x(x), y(y){}
    V operator+(const V& p) const {return V(x+p.x, y+p.y);}
    V operator-(const V& p) const {return V(x-p.x, y-p.y);}
    V operator*(double a) const {return V(x*a, y*a);}
    double sqrNorm() const {return x*x + y*y;}
    double norm() const {return sqrt(sqrNorm());}
    //時計回りに90度回転
    V rotate90() const {return V(y, -x);}
};

// 円の計算
struct Circle{
    //ベクトルの中心座標o,半径をｒでもつ
    V o; double r;
    Circle(V o=V(), double r=0): o(o), r(r){}

    //交点計算 cross ponit
    vector<V> xp(const Circle& c){
        V v = c.o - o;
        //まず距離を求める
        double l = v.norm();
        //中心が重なってるなら交点なし
        if(equal(l, 0)){
            return {};
        }
        //ちょうど直線になっている。交点が一つのみ。 
        if(equal(l+r+c.r, max({l,r,c.r})*2)){
            if( equal(l+r, c.r)){
                return {o - v*(r/l)};
            }
            else{
                return {o + v*(r/l)};
            }
        }
        //三角形が成り立たないので、交点なし
        //三角形の成り立つ条件は　三辺の和 >= 最大辺の2倍
        if(l+r+c.r < max({l, r, c.r})*2){
            return {};
        }

        double x = (l*l + r*r - c.r*c.r) / (2*l);
        //アフファの長さ
        double y = sqrt(r*r - x*x);
        V mid = o + v*(x/l);
        v = v.rotate90();
        return {mid + v*(y/l), mid - v*(y/l)};
    }
    //点が円の中に入っているのか
    bool isInside(const V& p) const {
        //点と中心の距離がr以下ですか？ epsで境界も含むようにする。
        return (p-o).norm() < r+eps;
    }
};

int main(){
    int n, k;
    cin >> n >> k;

    if( k==1){
        cout << 0 << endl;
        return 0;
    }
    vector<Circle> c(n);
    for(int i=0; i<n; ++i){
        cin >> c[i].o.x >> c[i].o.y >> c[i].r;
    }

    double l = 0, r = 400000;
    //二部探索
    //doubleで二分探索するとwhiledだと収束せずに無限ループするので、回す回数を固定する。
    for(int ti=0; ti<100; ++ti){
        //時間をｘとする
        double x = (l+r)/2;
        //候補点
        vector<V> ps;
        //中心の点
        for(int i=0; i<n; ++i) ps.push_back(c[i].o);
        //交点
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                Circle a = c[i], b = c[j];
                a.r = x/a.r;
                b.r = x/b.r;
                //ベクトルのベクトル（0 or 1 0r 2個のベクトルがはいっている）
                auto tmp = a.xp(b);
                ps.insert(ps.end(), tmp.begin(), tmp.end());
            }
        }
        bool ok = false;
        for( V p : ps){
            int cnt = 0;
            for(int ci =0; ci<n; ++ci){
                Circle nc = c[ci];
                nc.r = x/nc.r;
                if(nc.isInside(p)){
                    cnt++;
                }
            }
            if(cnt >= k){
                ok = true;
            }
        }
        if(ok){
            r = x;
        }else{
            l = x;
        }
    }

    printf("%.10f\n", r);
}
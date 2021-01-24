#include <bits/stdc++.h>
using namespace std;

//x の最も下の立っているビットは，x & -x で取り 出せる
template <class T> class BIT{
    private:
    vector<T> array;
    const int n;
    
    public:
    //constractor
    BIT(int _n) : array(_n + 1, 0), n(_n){}
    
    //sum [0,i]
    T sum(int i){
        T s = 0;
        while(i > 0){
            s += array[i];
            i -= i & -i;
        }
        return s;
    }

    //sum [i,j]
    T sum(int i, int j){
        T ret_i = sum(i -1);
        T ret_j = sum(j);
        return ret_j - ret_i;
    }

    // 1-index
    void add(int i, T x){
        while(i <= n){
            array[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    long long n, d, a;
    cin >> n >> d >> a;
    vector<pair<long long,long long>> p(n+1);
    for(int i=1; i<=n; ++i) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    long long ans = 0;
    BIT<long long> bit(n+1);
    for(int i=1; i<=n; ++i){
        long long x = p[i].first;
        long long h = p[i].second;
        h -= bit.sum(i);
        if( h <= 0) continue;

        long long num = (h+a-1)/a;
        ans += num;
        long long damage = num*a;
        bit.add(i, damage);
        long long rx = min(x+d*2, (long long)100100100111);
        long long j = upper_bound(p.begin(), p.end(), make_pair(rx+1LL, -1LL) ) - p.begin();
        bit.add(j, -damage);
    }

    cout << ans << endl;
}


// imos like
// int main(){
//     int n;
//     long long d, a;
//     cin >> n >> d >> a;

//     vector<pair<long long, long long>> p(n);
//     for(int i=0; i<n; ++i){
//         cin >> p[i].first >> p[i].second;
//     }

//     sort(p.begin(), p.end());
//     d = d * 2;
//     long long tot = 0;
//     queue<pair<long long, long long>> q;
//     long long ans = 0;

//     //imos法likeにとく
//     for(int i=0; i<n; ++i){
//         long long x = p[i].first;
//         long long h = p[i].second;
//         //座標の有効期限が切れたら引く
//         while(q.size() && q.front().first < x){
//             tot -= q.front().second;
//             q.pop();
//         }
//         h -= tot;
//         if(h > 0){
//             long long num = (h+a-1)/a;
//             ans += num;
//             long long damage = num *a;
//             tot += damage;
//             q.emplace(x+d, damage);
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// //example of range add query
// class LazySegmentTree{
// private:
//     int n;
//     vector<long long> node, lazy;
    
// public:
//     LazySegmentTree(vector<long long> v){
//         int sz = (int)v.size();
//         n = 1;
//         while(n < sz) n *= 2;
//         node.resize(2*n-1);
//         lazy.resize(2*n-1, 0);

//         for(int i=0; i<sz; ++i){
//             node[i+n-1] = v[i];
//         }
//         for(int i=n-2; i>=0; --i){
//             node[i] = node[i*2+1] + node[i*2+2];
//         }
//     }


//     //kが現在の評価ノートの遅延電波。lとrが指定範囲[l,r)
//     void eval(int k, int l, int r){
//         // 遅延配列が空でない場合、自ノード及び子ノードへの
//         // 値の伝播が起こる
//         if(lazy[k] != 0){
//             node[k] += lazy[k];

//             // 最下段かどうかのチェックをしよう
//             // 子ノードは親ノードの 1/2 の範囲であるため、
//             // 伝播させるときは半分にする
//             if(r - l > 1){
//                 lazy[2*k+1] += lazy[k]/2;
//                 lazy[2*k+2] += lazy[k]/2;
//             }

//             // 伝播が終わったので、自ノードの遅延配列を空にする
//             lazy[k] = 0;
//         }
//     }
    
//     //区間加算
//     // 区間[a,b)に関して、x:加える値ノードk=[l,r)に着目している。
//     // [l,r)の初期値は全体
//     void add(int a, int b, long long x, int k=0, int l=0, int r = -1){
//         if(r < 0) r = n;
//         eval(k, l, r);
//         // 交差しない場合
//         if(r <= a || b <= l) return;

//         // a,l,r,bの順で完全に含まれる
//         if(a <= l && r <= b){
//             lazy[k] += (r-l) * x;
//             eval(k, l, r);
//         }else{
//             add(a, b, x, 2*k+1, l, (l+r)/2);
//             add(a, b, x, 2*k+2, (l+r)/2, r);
//             node[k] = node[2*k+1] + node[2*k+2];
//         }
//     }

// 	//[a, b)の和
//     long long getsum(int a, int b, int k=0, int l=0, int r =-1){
//         if(r < 0) r=n;
//         //ノードが呼び出されたら評価
//         eval(k, l, r);

//         if(b <= l || r <= a) return 0;
//         if(a <= l && r <= b) return node[k];
//         long long vl = getsum(a, b, 2*k+1, l, (l+r)/2);
//         long long vr = getsum(a, b, 2*k+2, (l+r)/2, r);
//         return vl + vr;
//     }
// };

// int main(){
// 	long long N, D, A;
// 	cin >> N >> D >> A;
// 	long long len = 1000000;
// 	vector<pair<long long, long long>> x_life(N);
// 	for(int i=0; i< N; ++i){
// 		long long x, h; cin >> x >> h;	x--;
// 		x_life[i] = {x, h};
// 	}
// 	sort(x_life.begin(), x_life.end());

// 	vector<long long> compressed_x_original_x(N);
// 	vector<long long> compressed_x_life(N);
// 	int idx = 0;
// 	for(auto idx_life : x_life){
// 		compressed_x_original_x[idx] = idx_life.first;
// 		compressed_x_life[idx] = idx_life.second;
// 		idx++;
// 	}

// 	LazySegmentTree LsegTree(vector<long long>(N+1, 0));
// 	long long total_attack_count = 0;

// 	//狐の数だけ回す
// 	for(int i=0; i<x_life.size(); ++i){
// 		long long current_idx = compressed_x_original_x[i];
// 		//long long life = compressed_x_life[i];
// 		//2Dの範囲まで
// 		long long dist = current_idx+2*D;
// 		dist = min(dist, (long long)1e+9 );
// 		//どこまで攻撃できるかを計算
// 		long long end_idx = lower_bound(compressed_x_original_x.begin(), compressed_x_original_x.end(), dist) - compressed_x_original_x.begin();
// 		//境界条件に注意、その範囲をちょうど満たす場合は一個次まで入れる。
// 		if( compressed_x_original_x[end_idx] == dist ){
// 			end_idx++;
// 		}

// 		//現在の蓄積ダメージ
// 		long long cur_damage = LsegTree.getsum(i,i+1);
// 		long long cur_monster_life = compressed_x_life[i] - cur_damage;
// 		//もし倒してるんなら計算しない
// 		if(cur_monster_life <= 0 ) continue;
// 		//まだ倒してないなら倒すのに必要な攻撃回数
// 		long long cur_monster_attack_count = (cur_monster_life +A-1)/A;
// 		//RAQ（dist_idx攻撃範囲なのでidx + 1）
// 		LsegTree.add(i, end_idx, A*cur_monster_attack_count);
// 		total_attack_count += cur_monster_attack_count;
// 	}

// 	cout << total_attack_count << endl;
// }


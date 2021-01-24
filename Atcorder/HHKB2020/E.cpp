#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

// 素数 p で割ったあまりに関する構造体 (特に p = 1000000007 とすることが多い)
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mint = Fp<1000000007>;

// 時計回り90度
void rot(vector<vector<int>>& a){
    int h = a.size(), w = a[0].size();
    vector<vector<int>> pre(w, vector<int>(h));
    swap(a, pre);
    for(int i=0; i<w; ++i){
        for(int j=0; j<h; ++j){
            a[i][j] = pre[h-1-j][i];
        }
    }
}

int main(){
    //各置き方において各マスで照らされているかの和
    //= 各マスにおいて各置き方で照らされる回数
    //各置き方で該当のマスが何回照らせれるかは全体-該当マスを照らさない置き方で計算可能
    //照らせない回数は回転を用いて４方向を確かめる

    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for(int i=0; i<H; ++i){
        cin >> s[i];
    }
    //盤面の0,1に置き換える
    vector<vector<int>> a(H, vector<int>(W));
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            a[i][j] = s[i][j] == '.';
        }
    }

    //2の累乗を前計算
    int n = H*W;
    vector<mint> two(n+1, 1);
    for(int i=0; i<n; ++i){
        two[i+1] = two[i] *2;
    }

    int k = 0;
    //ksには見える照らし型を入れる
    vector<vector<int>> ks = a;

    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            k += a[i][j];
        }
    }

    //4回転
    for(int ri=0; ri<4; ++ri){
        vector<vector<int>> d(H, vector<int>(W));
        for(int i=0; i<H; ++i){
            for(int j=0; j<W-1; ++j){
                if(a[i][j]) d[i][j]++;
                else d[i][j] = 0;
                if(a[i][j+1]) ks[i][j+1] += d[i][j];
                d[i][j+1] = d[i][j];
            }
        }
        rot(a);
        rot(ks);
        swap(H, W);
    }

    mint ans = two[k]*n;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            int x = k - ks[i][j];
            ans -= two[x];
        }
    }

    cout << ans << endl;
}
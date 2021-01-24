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

// 二項係数ライブラリ
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};

// 1000000007 で割ったあまりのクラス
using mint = Fp<1000000007>;

mint tate(int N, int A, int B){
    //Aの置き方
    mint Anum = (N-A+1);
    //Bの置き方の横の個数（これは定数）
    mint Byoko = (N-B+1);
    //Bの置き方の縦の個数（区切り線が何個あるか)
    //x  = B~ N-A より
    //x' = 1 ~ (N-A-B+1);
    mint R = N-A-B+1;

    mint Btate = R*(R+1)/2;
    mint ans = Anum * Byoko * Btate;
    //もしRが負ならそもそも成り立たないので考慮しない
    if( (N-A-B+1)< 0) ans = 0;

    return ans;
}

//重複分
mint naname(int N, int A, int B){
    //Aの置き方は縦線と横線の両方にあるので固定されるため、
    mint Anum = 1; 
    //Bの置き方
    mint R =  N-A-B+1;

    //xもyも通りは同じ
    mint xdash = R*(R+1)/2;
    mint ydash = R*(R+1)/2;
    //シグマの法則より
    mint Bnum = xdash * ydash;
    mint ans = Anum * Bnum;

    //もしRが負ならそもそも成り立たないので考慮しない
    if( (N-A-B+1)< 0) ans = 0;
    return ans;
}

mint solve(int N, int A, int B){
    //takeは上下左右反転で*2、されるyokoも同じことをやるので全体で*4
    //nanameも回転すると全部で4通り
    mint ans = tate(N, A, B) * 4 - naname(N, A, B) *4;
    return ans;
}

int main(){
    int T; cin >> T;
    for(int qi =0; qi<T; ++qi){
        int N, A, B;
        cin >> N >> A >> B;
        cout << solve(N, A, B) << endl; 
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using namespace std;

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

int main(){
    int N; cin >> N;
     // 1000000007 で割ったあまりのクラス
    using mint = Fp<1000000007>;

    mint all = 1;
    mint no_zero = 1;
    mint no_zero_one = 1;

    for(int i=0; i<N; ++i){
        all *= 10;
    }

    for(int i=0; i<N; ++i){
        no_zero *= 9;
    }

    mint no_one = no_zero;


    //0も1も出ない
    for(int i=0; i<N; ++i){
        no_zero_one *= 8;
    }

    mint one_or_zero = all - no_zero_one;
    mint has_one = all - no_zero;
    mint has_zero = has_one;

    mint ans = has_zero + has_one;
    ans -= one_or_zero;

    cout << ans << endl;

}

// const long long MOD = 1e9 + 7;

// int main(){
//     long long N;
//     cin >> N;

//     long long all = 1;
//     long long no_zero = 1;
//     long long no_zero_one  = 1;

//     //全体
//     for(int i=0; i<N; ++i){
//         all *= 10;
//         all %= MOD;
//     }

//     //0が1つでも存在
//     for(int i=0; i<N; ++i){
//         no_zero *= 9;
//         no_zero %= MOD;
//     }

//     long long no_one = no_zero;

//     //0も1も出ない
//     for(int i=0; i<N; ++i){
//         no_zero_one *= 8;
//         no_zero_one %= MOD;
//     }

//     long long one_or_zero = all - no_zero_one;
//     one_or_zero %= MOD;

//     long long has_one = all - no_zero;
//     has_one %= MOD;

//     long long has_zero = has_one;
//     has_zero %= MOD;

//     long long ans = has_zero + has_one;
//     ans %= MOD;
//     ans -= one_or_zero;
//     ans %= MOD;


//     //1かつ0が存在
//     cout << ans << endl;
// }
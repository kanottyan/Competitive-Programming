//https://qiita.com/drken/items/f2ea4b58b0d21621bd51#7-1-スターリング数の実装
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 510000;
const int MOD = 1e9 + 7;

long long fac[MAX], inv[MAX], finv[MAX];

void COMinit(){
    fac[0]= fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;

    for(int i =2; i < MAX; ++i){
        fac[i] = fac[i-1] * i;
        inv[i] = MOD - inv[MOD%i]* (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[n-k] * finv[k] %MOD) % MOD;
}

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
    // 1000000007　で割ったあまりのクラス
    using mint = Fp<1000000007>;
    
    // 二項係数計算の前処理 (nCk, n, k < 101010 について O(1) でとれるようにする)
    BiCoef<mint> bc(101010);

    COMinit();

    //スターリング数
    //S(n,k)=S(n−1,k−1)+kS(n−1,k)
    //S(n,k)=(1/k!)*(∑[i=0-k] (−1)^(k−i) * kCi * i^n)
    int n, k ;
    cin >> n >> k;
    mint res = 0;
    for (int i = 0; i <= k; ++i) {
        // mint add = bc.com(k, i) * modpow(mint(i), n);
        mint add = COM(k, i) * modpow(mint(i), n);

        if ((k-i) % 2 == 0) res += add;
        else res -= add;
    }

    // k!で割る
    res *= bc.finv(k);

    cout << res << endl;

}
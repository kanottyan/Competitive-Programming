#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
//using mint = modint1000000007;


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

const int MOD = 1000000007;
using mint = Fp<MOD>;


int main() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    for(int i=0;i<n; ++i) cin >> l[i] >> r[i];

    vector<int> xs(1, 0);
    for(int i=0; i<n; ++i){
        xs.push_back(l[i]);
    }

    for(int i=0; i<n; ++i){
        xs.push_back(r[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    vector<mint> p(n+1);
    p[0] = 1;

    auto mul = [&](int a){
        for(int i=n-1; i>=0; --i){
            p[i+1] += p[i];
            p[i] *= -a;
        }
    };

    auto div = [&](int a){
        if(a){
            //mint inva = mint(1)/-a;
            mint inva = mint(-1)/a;

            for(int i=0; i<n; ++i){
                p[i] *= inva;
                p[i+1] -= p[i];
            }
        }else{
            for(int i=0; i<n; ++i){
                p[i] = p[i+1];
                p[i+1] = 0;
            }
        }
    };

    vector<mint> invs(n+2);
    for(int i=1; i<=n+1; ++i){
        mint tmp = mint(1)/i;
        invs[i] = tmp;
        // invs[i] = mint(1)/i;
    }
    int px = 0;
    int zero = n;
    mint co = 1;
    mint ans = 0;


    for(int x : xs){
        auto f = [&](int X){
            if(zero) return mint(0);
            mint res; 
            mint nx = 1;
            for(int i=0; i<n+1; ++i){
                nx *= X;
                //res += p[i]*nx*invs[i+1];
                mint tmp = p[i]*nx;
                tmp *= invs[i+1];
                res += tmp;
            }
            return res*co;
        };
        ans += f(x) - f(px);

        for(int i=0; i<n; ++i){
            if(l[i] == x){
                zero--;
                mul(l[i]);
            }
            if(r[i] == x){
                div(l[i]);
                mint tmp = (r[i] - l[i]);
                co *= tmp;
            }
        }
        px = x;
    }


    mint tot = 1;
    for(int i=0; i<n; ++i){
        tot *= r[i] - l[i];
    }
    tot *= px;
    ans = (tot - ans);
    for(int i=1; i<=n+1; ++i){
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}
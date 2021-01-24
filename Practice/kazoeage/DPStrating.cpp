//https://qiita.com/drken/items/f2ea4b58b0d21621bd51#7-1-2-スターリング数の漸化式計算

    //スターリング数
    //S(n,k)=S(n−1,k−1)+kS(n−1,k)
    //S(n,k)=(1/k!)*(∑[i=0-k] (−1)^(k−i) * kCi * i^n)

#include <iostream>
#include <vector>

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

template<class T> struct Stirling{
    vector<vector<T> > S;
    constexpr Stirling(int MAX) noexcept : S(MAX, vector<T>(MAX, 0)){
        S[0][0] = 1;
        for(int n=1; n< MAX; ++n){
            for(int k = 1; k <=n; ++k){
                S[n][k] = S[n-1][k-1] + S[n-1][k] * k;
            }
        }
    }
    constexpr T get(int n, int k){
        if(n <0 || k < 0 || n < k) return 0;
        return S[n][k];
    }
};

int main(){
    // 1000000007 で割ったあまりのクラス
    using mint = Fp<1000000007>;

    Stirling<mint> sl(3100); // S(n, k) を n, k < 3100 の範囲で求める
    // スターリング数
    int n, k;
    cin >> n >> k;
    cout << sl.get(n,k) << endl;


}
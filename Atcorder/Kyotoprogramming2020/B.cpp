#include <bits/stdc++.h>

using namespace std;

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
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
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};


const int MOD = 1000000007;
using mint = Fp<MOD>;

int N, K;
vector<vector<long long>> v;
vector<vector<long long>> memo_idx;
vector<vector<mint>> memo_num;

int main(){
    cin >> N >> K;    
    v.assign(N, vector<long long>(K));
    memo_idx.assign(N+1, vector<long long>(K, -1));
    memo_num.assign(N+1, vector<mint>(K, 0));


    for(int i=0; i<N; ++i){
        for(int j=0; j<K; ++j){
            cin >> v[i][j];
        }
    }

    for(int j=0; j<K; ++j){
        memo_idx[N-1][j] = K - j;
    }

    //累積和
    vector<mint> cumsum(K+1);
    cumsum[0] = 0;
    for(int j=1; j<K+1; ++j){
        cumsum[j] = j;
    }

    for(int row=N-2; row>=0; --row){
        vector<mint> new_cumsum(K+1);
        new_cumsum[0] = 0;
        for(int col=0; col<K; ++col){
            auto iter = lower_bound(v[row+1].begin(), v[row+1].end(), v[row][col]);
            int idx = iter - v[row+1].begin();
            mint tmp = cumsum[K] - cumsum[idx];
            new_cumsum[col+1] = (tmp + new_cumsum[col]);
        }
        cumsum = new_cumsum;
    }

    cout << cumsum[K] << endl;

}
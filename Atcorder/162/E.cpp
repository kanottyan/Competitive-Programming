#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9+7;

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

vector<pair<long long, long long> > prime_factorizer(long long N){
    vector< pair<long long, long long> > res;

    for(long long i = 2; i * i <= N; ++i){
        if( N %i != 0 ) continue;
        long long ex = 0;

        while(N%i == 0){
            ex++;
            N /= i;
        }
        res.push_back({ i, ex });
    }
    
    if(N != 1) res.push_back({N, 1});

    return res;
}

using mint = Fp<MOD>;

int main(){
    int N, K;
    cin >> N >> K;

    mint dp[K+1];
    for(int i=1; i<K+1; ++i){
        dp[i] =modpow(mint(K/i), N);
    }

    for(int i=K+1; i>0; --i){
        for(int j=2*i; j<K+1; j= j+i){
            dp[i] -= dp[j];
        }
    }

    mint ans = 0;
    for(int i=1; i<K+1; ++i){
        ans += (dp[i] * i);
    }

    cout << ans << endl;
}

// int main(){
//     int N, K;
//     cin >> N >> K;

//     unordered_map<int, int> um;

//     for(int i=1; i<=K; ++i){
//         const auto& res = prime_factorizer(i);
//         for(auto p_ex : res){
//             um[p_ex.first] += 1;
//         }
//     }

//     //init ans
//     mint ans = modpow(mint(K), N);

//     for( auto p_ex : um ){
//         mint tmp = modpow(mint(p_ex.second), N);
//         tmp *= (p_ex.first - 1);
//         ans += tmp;
//     }

//     cout << ans << endl;
// }
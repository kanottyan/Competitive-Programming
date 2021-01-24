#include <bits/stdc++.h>
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

using mint = Fp<1000000007>;
BiCoef<mint> bc(2000010);


mint g(int r, int c){
    return bc.fact(r+c+2) * bc.finv(r+1) * bc.finv(c+1) -1;
}

int main(){
    // 1000000007 で割ったあまりのクラス

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    //直前を見たほうがやりやすいので--で一個前の点をみる
    r1--; c1--;
    mint ans = 0;

    //全体
    ans += g(r2,c2);
    //縦長
    ans -= g(r1, c2);
    //横長 
    ans -= g(r2,c1);
    //引きすぎた小さい四角形をもっかいたす
    ans += g(r1, c1);

    cout << ans << endl;
}

// int main() {
//     // 1000000007 で割ったあまりのクラス
//     using mint = Fp<1000000007>;
//     BiCoef<mint> bc(2000010);

//     int r1, c1, r2, c2;
//     cin >> r1 >> c1 >> r2 >> c2;


//     //y軸の計算
//     auto calcu_y = [&](mint k, int r){
//         mint ans = k;

//         for(int i=1; i<=c2-c1; ++i){
//             k *= (c1+r+i);
//             k /= (c1+i);
//             ans += k;
//         }
//         return ans;
//     };

//     //最初の1列目
//     mint res = 0;
//     mint bottom_x_in_column = bc.fact(r1+c1) * bc.finv(r1) * bc.finv(c1);
//     mint first_column = calcu_y(bottom_x_in_column, r1);
//     res += first_column;

//     mint curernt_column_sum = first_column;

//     for(int i=r1+1; i<=r2; ++i){
//         //前の列の最初のxを引く
//         mint bottom_x_prev_column = bc.fact(i-1+c1) * bc.finv(i-1) * bc.finv(c1);
//         curernt_column_sum -= bottom_x_prev_column;
//         //今の列の一番上の数をいれる
//         mint top_x_current_column = bc.fact(i+c2) * bc.finv(i) * bc.finv(c2);
//         curernt_column_sum += top_x_current_column;
        
//         curernt_column_sum *= (i+1+c1);
//         curernt_column_sum /= (i+1);
//         res += curernt_column_sum;

//         // for(int j=c1; j<=c2; ++j){
//         //     mint tmp = bc.fact(i+j) *bc.finv(i) * bc.finv(j);
//         //     res += tmp;
//         // }
//     }

//     cout << res << endl;

// }
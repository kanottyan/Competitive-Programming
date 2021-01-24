#include <iostream>
#include <vector>
using namespace std;

// 負の数にも対応した mod
// 例えば -17 を 5 で割った余りは本当は 3 (-17 ≡ 3 (mod. 5))
// しかし単に -17 % 5 では -2 になってしまう

inline long long mod(long long a, long long m){
    return (a%m +m) %m;
}

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2){
    long long p,q;
    long long d = extGcd(m1, m2, p, q);
    if((b2-b1)%d !=0) return make_pair(0, -1);
    long long m = m1*(m2/d); // lcm of(m1,m2);
    long long tmp = (b2-b1)/d*p%(m2/d);
    long long r = mod(b1+m1*tmp, m);
    return make_pair(r, m);
}
//「3 で割ったあまりが 2」かつ「5 で割ったあまりが 3」という条件は、「15 で割ったあまりが 8」
int main(){
    pair<long long, long long> res = ChineseRem(2,3,3,5);
    cout << "x ≡ " << res.first << " (mod. " << res.second << ")" << endl;
}
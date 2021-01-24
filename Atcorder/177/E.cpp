#include <bits/stdc++.h>
using namespace std;

const int A = 100;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    //頻度を求める配列
    vector<int> c(A);

    for(int i=0; i<n; ++i){
        cin >> a[i];
        c[a[i]]++;
    }

    bool pairwise = true;
    for(int i=2; i< A; ++i){
        int cnt = 0;
        for(int j=i; j<A; j += i){
            cnt += c[j];
        }
        if(cnt > 1) pairwise = false;
    }

    if(pairwise){
        cout << "pairwise coprime" << endl;
        return 0;
    }

    //gcd(0, x) =x なので初期値は0が都合良い
    int g = 0;
    for(int i=0; i<n; ++i){
        g = gcd(g, a[i]);
    }

    if(g == 1){
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
    return 0;
}

// long long GCD(long long a, long long b) {
//     if (b == 0) return a;
//     else return GCD(b, a % b);
// }

// vector<pair<long long, long long> > prime_factorize(long long N) {
//     vector<pair<long long, long long> > res;
//     for (long long a = 2; a * a <= N; ++a) {
//         if (N % a != 0) continue;
//         long long ex = 0; // 指数

//         // 割れる限り割り続ける
//         while (N % a == 0) {
//             ++ex;
//             N /= a;
//         }

//         // その結果を push
//         res.push_back({a, ex});
//     }

//     // 最後に残った数について
//     if (N != 1) res.push_back({N, 1});
//     return res;
// }

// int main(){
//     long long N;
//     cin >> N;
//     vector<long long> A(N);

//     for(int i=0; i<N; ++i){
//         cin >> A[i];
//     }

//     long long g = GCD(A[0], A[1]);
//     bool one_flag = true;
//     bool other_flag = false;
//     set<long long> s;

//     if(g == 1){
//         other_flag = false;
//         auto res = prime_factorize(A[0]);
//         for(auto pe: res){
//             s.insert(pe.first);
//         }
//         res = prime_factorize(A[1]);
//         for(auto pe: res){
//             s.insert(pe.first);
//         }
//     }else{
//         other_flag = true;
//     }


//     for(int i=1; i<N-1; ++i){
//         auto res = prime_factorize(A[i+1]);
//         for(auto pe: res){
//             if(s.count(pe.first) > 0){
//                 other_flag = true;
//             }else{
//                 s.insert(pe.first);
//             }
//         }

//         g = GCD(g, A[i+1]);
//     }


//     if(g == 1){
//         one_flag = true;
//     }else{
//         one_flag = false;
//     }

//     if(one_flag){
//         if(other_flag){
//             cout << "setwise coprime" << endl;
//         }else{
//             cout << "pairwise coprime" << endl;
//         }
//     }else{
//         cout << "not coprime" << endl;
//     }

// }
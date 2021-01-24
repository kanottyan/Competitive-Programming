//https://atcoder.jp/contests/abc150/tasks/abc150_d
//https://qiita.com/drken/items/a14e9af0ca2d857dad23#問題-10-abc-150-d---semi-common-multiple-400-点

#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long x, long long y){
    if(y == 0) return x;
    else return GCD( y, x%y );
}

long long solve(int N, long long M, vector<long long> &a){
    //2で割れるだけわる
    while( a[0] %2 == 0 ){
        for(int i=0; i<N; ++i){
            if(a[i] %2 != 0) return 0;
            a[i] /= 2;
        }
        M/=2;
    }

    //ord2が違ったらretur 0
    for (int i = 0; i < N; ++i){
        if (a[i] % 2 == 0) return 0;
    } 

    // lcm
    long long lcm = 1;
    for( int i=0; i<N; ++i){
        long long g = GCD(lcm, a[i]);
        lcm = lcm/g * a[i];
        // if lcm beyond M return zero.
        // if we don't do this lcm might overflow and cause wrong answer.
        if(lcm > M) return 0;
    }
    return (M / lcm +1)/2;
}

int main(){
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> a(N);
    for(int i=0; i<N; ++i) {
        cin >> a[i];
        a[i] /= 2;
    }

    cout << solve(N, M, a) << endl;

}

//atcoder answer

// long long GCD(long long x, long long y){
//     if(y == 0) return x;
//     else return GCD( y, x%y );
// }

// long long LCM(long long a, long long b){
//     return a/GCD(a, b) * b;
// }

// int f(int x){
//     int res = 0;
//     while(x%2 ==0){
//         x /=2;
//         res++;
//     }
//     return res;
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i=0; i<n; ++i){
//         cin >> a[i];
//         // a --> a'
//         a[i] /= 2;
//     }

//     int t = f(a[0]);
//     for(int i=1; i<n; ++i){
//         if(f(a[i] != t)){
//             cout << 0 << endl;
//             return 0;
//         }

//         a[i] >>= t; // a[i] /= 2^t;
//     }

//     m >>= t;

//     long long l = 1;
//     for(long long i=0; i<n; ++i){
//         l = LCM(l, a[i]);
//         if( l > m ){
//             cout << 0 << endl;
//             return 0;
//         }
//     }

//     m /= l;
//     int ans = (m+1)/2;
//     cout << ans << endl;


//     return 0;
// }

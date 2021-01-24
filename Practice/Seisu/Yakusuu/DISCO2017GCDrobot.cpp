//https://atcoder.jp/contests/ddcc2017-final/tasks/ddcc2017_final_b
//https://qiita.com/drken/items/0c88a37eec520f82b788#問題-10-disco-presents-ディスカバリーチャンネル-コードコンテスト2017-本戦-b---gcdロボット-500-点

#include <vector>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    long long g = gcd(a, b);
    return a / g * b;
}

int main(){
    int N; cin >> N;
    long long Z; cin >> Z;
    vector<long long> a(N);

    for(int i=0; i<N; ++i){
        cin >> a[i];
    }

    long long ans = 1;
    for(int i=0; i<N; ++i){
        long long g = gcd( a[i], Z);
        ans = lcm(ans, g);
    }

    cout << ans << endl;
}

// int main(){
//     int N;
//     cin >> N;
//     long long Z;
//     cin >> Z;
//     vector<int> a(N);

//     for(int i=0; i<N; ++i){
//         cin >> a[i];
//     }

//     vector<long long> ans(N);
//     for(int i=0; i<N; ++i){
//         ans[i] = gcd(Z, a[i]);
//     }

//     long long num = 1;
//     while(true){
//         bool flag = true;
//         for(int i=0; i<N; ++i){
//             long long g = gcd(num, a[i]);
//             if( g != ans[i]) flag = false;
//         }
        
//         if(flag){
//             break;
//         }else{
//             num++;
//         }
//     }

//     cout << num << endl;

// }
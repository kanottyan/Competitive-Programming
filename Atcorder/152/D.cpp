#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int N;
int table[10][10];

int first_digit(int n){
    while(n >= 10){
        n /= 10;
    }
    return n;
}

int last_digit(int n){
    return n%10;
}

void init(){
    //何回あるのかを調べる
    for(int i=1; i<=N; ++i){
        int f = first_digit(i);
        int l = last_digit(i);
        table[f][l]++; 
    }
}

int main(){
    cin >> N;
    init();
    long long ans = 0;
    for(int i=1; i<=N; ++i){
        int f = first_digit(i);
        int l = last_digit(i);
        ans += table[l][f];
    }

    cout << ans << endl;
}


//digit dp を使おうとして諦めたやつ
// long long zero_num(int s, int e){
//     long long add = 90;
//     long long cnt = 9;
//     long long ans = 1;
//     long long num = s*10 + e;


//     if(num > N){
//         ans--;
//     }

//     while(num <= N){
//         num += add;
//         if(num <= N){
//             ans += cnt;
//             cnt *= 9;
//         }
//         add *= 10;
//     }

//     return ans;
// }


// int cnt(int s, int e){
//     int res = 0;
//     int num = s*10 + e;

//     if(s == e){
//         if(s <= N){
//             res++;
//         } 
//     }

//     if(num < N){
//         //90ふやしてく
//         res += zero_num(e, s); //* zero_num(e, s);
//     }
//     return res;

// } 



// int main(){
//     cin >> N;

//     long long ans = 0;

//     for(int i=1; i<=N; ++i){
//         if(i < 10){
//             ans += cnt(i, i);
//             cout << i << ": " << cnt(i, i) << endl;
//         }else{
//             int s = to_string(i)[0] - '0';
//             int e = to_string(i).back() - '0';
//             if(e == 0) continue;

//             ans += cnt(s, e);
//             cout << i << ": " << cnt(s, e) << endl;
//         }
//     }

    // for(int i=1; i<=9; ++i){
    //     for(int j=1; j<=9; ++j){
    //         ans += cnt(i, j);
    //         cout << i << "," << j << ": " << cnt(i, j) << endl;
    //     }
    // }
//     cout << ans << endl;
// }
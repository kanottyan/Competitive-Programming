#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int INF = 1001001001;

int main(){
    string s; cin >> s;
    int n = s.size();

    vector<int> c(3, 0);
    for(int i=0; i<n; ++i ){
        c[(s[i]- '0')%3]++;
    }
    int x= 0;
    for(int i=0; i<3; ++i){
        x += c[i] * i;
    }

    int ans = INF;
    
    //i1は1を消す,i2は2を消す
    for(int i1=0; i1<3; ++i1){
        for(int i2=0; i2<3; ++i2){
            if(c[1] < i1) continue;
            if(c[2] < i2) continue;
            //全部消すのもだめ
            if(i1 + i2 == n) continue;
            int nx = x;
            nx -= i1*1;
            nx -= i2*2;
            if(nx %3 == 0) ans = min(ans, i1+i2);
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}

// int main(){
//     int sum = 0;
//     string s; cin >> s;
//     vector<int> A(3, 0);
//     for(int i=0; i<s.size(); ++i){
//         int num = s[i] - '0';
//         sum += num%3;
//         num %= 3;
//         A[num]++;
//         if(A[num] >= 3){
//             A[0]++;
//         }
//     }

//     int ans = 0;
//     if((A[0] == 0 && sum < 3) || (A[0] == 0 && sum == 4)){
//         if(A[1] == 2 && A[2] == 1){
//             ans = abs(A[1] - A[2]);
//             ans = min(ans, abs(A[1]%3 - A[2]%3));
//         }else{
//             ans = -1;
//         }
//     }else{
//             ans = abs(A[1] - A[2]);
//             ans = min(ans, abs(A[1]%3 - A[2]%3));
//     }
//     cout << ans << endl;

//     return 0;
// }
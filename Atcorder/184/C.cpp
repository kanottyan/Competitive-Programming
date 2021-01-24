#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

//Atcoder 解:0,0にスタート置く
int solve(int x, int y){
    //そこにある
    if( x == 0 && y == 0 ) return 0;
    //斜めでいける
    if(x+y == 0) return 1;
    if(x-y == 0) return 1;
    //マンハッタン距離一回出いける
    if(abs(x)+abs(y) <= 3) return 1;
    //斜めに２回でいける
    if((x+y)%2 == 0) return 2;
    //マンハッタン距離２回出いける
    if(abs(x)+abs(y)<= 6) return 2;
    //斜め一回行って、マンハッタン距離したら行ける
    if(abs(x+y) <= 3 ) return 2; 
    if(abs(x-y) <= 3 ) return 2; 
    //それ以外は三回必要
    return 3;
}

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << solve(x2-x1, y2-y1) << endl;
    return 0;
}


// //Atcoder 解
// int solve(){
//     int x1, y1, x2, y2;
//     cin >> x1 >> y1 >> x2 >> y2;
//     //そこにある
//     if( x1 == x2 && y1 == y2 ) return 0;
//     //斜めでいける
//     if(x1+y1 == x2+y2) return 1;
//     if(x1-y1 == x2-y2) return 1;
//     //マンハッタン距離一回出いける
//     if(abs(x1-x2)+abs(y1-y2) <= 3) return 1;
//     //斜めに２回でいける
//     if((x1+y1)%2 == (x2+y2)%2) return 2;
//     //マンハッタン距離２回出いける
//     if(abs(x1-x2)+abs(y1-y2)<= 6) return 2;
//     //斜め一回行って、マンハッタン距離したら行ける
//     if(abs((x1+y1)-(x2+y2)) <= 3 ) return 2; 
//     if(abs((x1-y1)-(x2-y2)) <= 3 ) return 2; 
//     //それ以外は三回必要
//     return 3;
// }

// int main(){
//     cout << solve() << endl;
//     return 0;
// }

// 自分の解
// int main(){
//     long long r1, c1, r2, c2;
//     cin >> r1 >> c1 >> r2 >> c2;

//     long long gx = 0;
//     long long gy = 0;
//     long long sx = r2 - r1;
//     long long sy = c2- c1;

//     if(sx == gx && sy == gy){
//         int ans = 0;
//         cout << ans << endl;
//         return 0;
//     }

//     for(int dx=-2; dx<=2; ++dx){
//         for(int dy=-2; dy<=2; ++dy){
//             if(sx + dx == gx && sy+dy == gy ){
//                 int ans = 1;
//                 cout << ans << endl;
//                 return 0;
//             }
//         }

//         if(sx - 3 == gx && sy == gy ){
//             int ans = 1;
//             cout << ans << endl;
//             return 0;
//         } 
//         if(sx + 3 == gx && sy == gy ){
//             int ans = 1;
//             cout << ans << endl;
//             return 0;
//         }
        
//         if( sx == gx && sy -3 == gy ){
//             int ans = 1;
//             cout << ans << endl;
//             return 0;
//         }

//         if( sx == gx && sy + 3 == gy ){
//             int ans = 1;
//             cout << ans << endl;
//             return 0;
//         }
//     }

//     if(sx == 0 && min(sy -sx, sx +sy) <=6 ){
//         cout << 2 << endl;
//         return 0;
//     }

//     //step2
//     sy = min(abs(sy - sx), abs(sy+sx));
//     sx = 0;

//     if(sx == gx && sy == gy){
//             int ans = 1;
//             cout << ans << endl;
//             return 0;
//     }

//     for(int dx=-2; dx<=2; ++dx){
//         for(int dy=-2; dy<=2; ++dy){
//             if(sx + dx == gx && sy+dy == gy ){
//                 int ans = 2;
//                 cout << ans << endl;
//                 return 0;
//             }
//         }

//         if(sx - 3 == gx && sy == gy ){
//             int ans = 2;
//             cout << ans << endl;
//             return 0;
//         } 
//         if(sx + 3 == gx && sy == gy ){
//             int ans = 2;
//             cout << ans << endl;
//             return 0;
//         }
        
//         if( sx == gx && sy -3 == gy ){
//             int ans = 2;
//             cout << ans << endl;
//             return 0;
//         }

//         if( sx == gx && sy + 3 == gy ){
//             int ans = 2;
//             cout << ans << endl;
//             return 0;
//         }
//     }

//     if( (sx + sy)%2 == 0 ){

//         cout << 2 << endl;
//         return 0;
//     }

//     cout << 3 << endl;
//     return 0;
// }


#include <bits/stdc++.h>
#include <atcoder/all>


using namespace std;
using namespace atcoder;

int main(){

    long long X, Y, A, B;
    cin >> X >> Y >> A >> B;

    long long cnt = 0;


    while(1){
        //オーバーフローしないのを確認
        if(Y/A <X) break;
        //A*Xが超えない確認
        if(A*X >= Y) break; 
        //A*Xが　X+Bよりも大きかったら+B戦略になる
        if(A*X >= X+B) break;
        X *= A;
        cnt++;
    }

    cnt += (Y-X-1)/B;
    cout << cnt << endl;
    return 0;
}

    // //掛け算が弱い場合
    // //先に掛け算を足し算に追いつくまでする
    // long long cnt = 0;
    // long long start = X;
    // while(B > start && start < Y){
    //     start *= A;
    //     cnt++;
    // }

    // if(start < Y){
    //     Y -= start;
    // }else{
    //     cnt--;
    //     start /=A;
    //     Y -= start;
    // }

    // long long tmp = (Y)/B;
    // cnt += tmp;
    // if(Y%B ==0) cnt--;
    // cout << cnt << endl;
    // return 0;

// }
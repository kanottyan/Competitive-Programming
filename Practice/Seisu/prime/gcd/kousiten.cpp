//https://qiita.com/drken/items/0c88a37eec520f82b788#4-互いに素への帰着


// 問題 4： 線分上の格子点の個数

// 平面上の二つの格子点 (ax,ay),(bx,by)
//  が与えられる。
// この二点を結ぶ線分上に何個の格子点があるか求めよ (両端を含まない)。
// −109≤ax,ay,bx,by≤109
// (数値例)
// ・(1,1),(5,5)

// 答え: 3
// (2,2),(3,3),(4,4)
//  の 3 個の格子点があります。


#include <vector>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    long long ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    long long g = gcd( abs(ax - bx), abs(ay - by) );
    cout << g - 1 << endl;


}
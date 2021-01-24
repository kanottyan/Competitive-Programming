//https://www.youtube.com/watch?v=pIHwC1wJgxw
//https://qiita.com/drken/items/b97ff231e43bce50199a#2-ユークリッドの互除法の原理


// return: GCD of a and b
// ax + by = GCD(a,b)を満たす(x,y)が格納される

#include <iostream>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main(){
    long long x, y;
    long long res = extGCD(15853, 12533, x, y);
    cout << x << "," << y << endl;
}
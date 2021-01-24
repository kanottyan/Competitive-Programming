//https://qiita.com/drken/items/3fe1613c44de1f3bfbe1
//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    long long n, m, d;
    cin >> n >> m >>d;
    double res;

    if(d == 0){
        res = (double)(m-1)/n;
    }else{
        res = (double)(m-1)*2*(n-d)/ n /n;
    }

    cout << fixed << setprecision(10) << res << endl;
}
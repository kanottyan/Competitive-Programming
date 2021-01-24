#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long one, zero, minus_one;
    cin >> one >> zero >> minus_one;

    long long K;
    cin >> K;

    long long res =0;

    long long a = one+zero;

    if( K <= one){
        res = K;
    }else if( one< K && K <=(one+zero) ){
        res = one;
    }else if( (one+zero) < K && K <= (one+zero+minus_one))
    {
        long long amari = K - (one+zero);
        res = one - amari;
    }else{
        res = one - minus_one;
    }

    cout << res << endl;
}
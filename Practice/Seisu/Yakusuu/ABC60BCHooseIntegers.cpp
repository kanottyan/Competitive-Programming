#include <iostream>

using namespace std;


long long gcd(long long A, long long B){
    if(B==0) return A;
    else return gcd(B, A%B);
}

int main(){
    long long A, B , C;
    cin >> A >> B >> C;

    // for(int i=0; i<B-1; ++i){
    //     long long r = (A*i)%B;
    //     cout << A*i << " % " << B << " =" << r << endl;
    // }

    long long g= gcd(A, B);

    if(C%g == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
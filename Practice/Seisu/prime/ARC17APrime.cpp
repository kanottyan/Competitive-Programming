#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(long long N){
    if( N == 1) return false;
    for(long long i=2; i*i <= N; ++i){
        if(N%i == 0) return false;
    }
    return true;
}

int main(){
    long long N;
    cin >> N;
    if(is_prime) cout << "YES" << endl;
    else cout << "NO" << endl;
}

// int main(){
//     int N;
//     cin >> N;

//     bool flag = true;

//     for(int i = 2; i < sqrt(N)+1; ++i){
//         if( N%i == 0 ){
//             flag = false;
//             break;
//         }
//     }

//     if(flag) cout << "YES" << endl;
//     else cout << "NO" << endl;

// }
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const long long INF = 1LL<<60;
//const long long INF = 100;


int main(){
    long long A, B, N;
    cin >> A >> B >> N;
    long long ok = 0;
    long long ng = B;

    long long ans = 0;

    while( abs(ok - ng) > 1){
        long long mid = (ok + ng) /2;

        long long left = floor((A*mid)/B);
        long long right = A*floor((mid/B));
        long long calc = left - right;
        if(mid <= N){
            if(calc >= ans){
                ok = mid;
                ans = calc;        
            }else{
                ng = mid;
            }
        } 
        else{
            ng = mid;
        } 
    }

    cout << ans << endl;
}
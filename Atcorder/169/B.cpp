#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long inf = pow(10, 18);
// doubleは恐ろしい子...
//     long long  a = 999990000000001;
//     long long b = a * 999;
//     long long b2 = b/100;
//     long long c = a * 999.0;
//    long long c2 = c/100.0;

//     cout << a*a << endl;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);

    long long ans = 1;
    for(int i=0; i<N; ++i){
        long long num;
        cin >> num;
        if(num == 0) ans = 0;
        a[i] = num;
    }
    if(ans != 0){
        for(int i=0; i<N; ++i){

            long long original_ans = ans;
            ans = original_ans * a[i];

            //check overflow
            if( ans/a[i] != original_ans ){
                ans = -1;
                break;
            }

            if(ans > inf){
                ans = -1;
                break;
            }

            if(ans == 0){
                ans = -1;
                break;
            }
        }
    }

// 3
// 1000000000 1000000000 3

    cout << ans << endl;
}
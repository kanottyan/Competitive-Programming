//https://atcoder.jp/contests/abc008/tasks/abc008_3
//https://qiita.com/drken/items/3fe1613c44de1f3bfbe1

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int N;
int C[210];

int main(){
    int N; 
    cin >> N;

    vector<int> C(N);
    for(int i=0; i<N; ++i) cin >> C[i];

    double res = 0.0;

    for(int i=0; i<N; ++i){
        int num = 0;
        for(int j=0; j<N; ++j){
            if(j ==i) continue;
            if(C[i] % C[j] == 0) ++num;
        }
        res += (double) ((num+2)/2)/(num+1);
    }
    cout << fixed << setprecision(10) << res << endl;
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    } 

    // if (j>i) then j-i = Ai + Aj
    // means Ai + i = j - Aj
    map<long long, vector<long long> > left_val;

    for(int i=0; i<N; ++i){
        long long left = (i+1) + A[i];
        if(left > 0) left_val[left].push_back(i+1);
    }

    long long ans = 0;

    // check right value exist in the left value;
    for(int j=0; j<N; ++j){
        long long right = (j+1) - A[j];
        if( left_val.count(right) > 0 ){
            ans += left_val[right].size();
        }
    }

    cout << ans << endl;
}
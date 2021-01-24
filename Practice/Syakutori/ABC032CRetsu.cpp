//https://atcoder.jp/contests/abc032/tasks/abc032_c

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<long long> a(N);
    long long sum = 1;
    int res=0;
    for(int i=0; i<N; ++i) cin >> a[i];

    int right = 0;
    for(int left=0; left<N; ++left){
        if(a[left] == 0){
            res = N;
            break;
        }

        while(right<N && sum*a[right] <=K ){
            sum *= a[right];
            right++;
        }

        res = max(right - left, res);
        if(left == right) right++;
        else sum /= a[left];
    }
    cout << res << endl; 
}
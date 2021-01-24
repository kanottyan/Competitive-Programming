//https://atcoder.jp/contests/abc098/tasks/arc098_b

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];

    long long sum = 0;
    long long xorsum = 0;
    long long res = 0;
    int right = 0;


    for(int left=0; left<N; ++left){

        while(right <N && ((right == left) || (sum+a[right]) == (xorsum ^ a[right]) ) ){
            sum += a[right];
            xorsum = xorsum^a[right];
            right++;
        // int aa = sum+a[right];
        // int bb = xorsum ^ a[right];
        }


        res += right - left;
        sum -= a[left];
        xorsum = xorsum^a[left];

    }
    cout << res << endl;
}
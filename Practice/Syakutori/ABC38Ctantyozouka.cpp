//https://atcoder.jp/contests/abc038/tasks/abc038_c

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);

    for(int i=0; i<N; ++i) cin >> a[i];

    long long counter = 0;
    int right = 1;

    if(N == 0) return 0;

    for(int left=0; left<N; ++left){
        while(right<N && (right == left || a[right] > a[right -1] ) ){
            right++;
        }
        counter += right - left;

    }
    cout << counter << endl;
}
// 6
//0 1 2 3 4 5 6
// 1 5 2 3 4 2

// {0,0},{0,1}, {1,1},{2,2}, {2,3}, {2,4}, {3,3}, {3,4}, {4,4}, {5,5} 
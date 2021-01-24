//https://atcoder.jp/contests/arc022/tasks/arc022_2

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    set<int> s;

    for(int i=0; i<N; ++i) cin >> a[i];

    int right = 0;
    int length = 0;
    for(int left=0; left<N; ++left){
        while(right<N && s.count(a[right]) <1 ){
            s.insert(a[right]);
            right++;
        }

        length = max(length, right-left);
        if(left == right) right++;
        else s.erase(a[left]);
    }

    cout << length << endl;
}
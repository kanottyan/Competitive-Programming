//区間の長さの最小値」を求める問題

#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 100100100;

using namespace std;

int main(){
    int Q;
    cin >> Q;


    for(int i=0; i<Q; ++i){
        int n, num;
        cin >> n >> num;
        vector<int> a(n);

        for(int i=0; i<n; ++i) cin >> a[i];

            int mn = INF;
            int sum = 0;
            int right = 0;

            for(int left=0; left<n; ++left){
                while(right < n && sum < num){
                    sum += a[right];
                    right++;
                }
                if(sum < num) break;
                mn = max(right-left, mn);
                
                if(left - right == 1) ++right;
                sum -= a[left];
            }
            cout << mn << endl;    
    }
}
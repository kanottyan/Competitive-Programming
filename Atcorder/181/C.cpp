#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

//int X[2010];
//int Y[2010];

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> ten(N);
    for(int i=0; i<N; ++i){
        int x, y;
        cin >> x >> y;
        ten[i].first = x;
        ten[i].second = y;
    }

    string ans = "No";

    for(int i=0; i<N-2; ++i){
        for(int j=i+1; j<N-1; ++j){
            for(int k=j+1; k<N; ++k){
                vector<pair<int, int>> arr;
                arr.push_back(ten[i]);
                arr.push_back(ten[j]);
                arr.push_back(ten[k]);
                sort(arr.begin(), arr.end());

                //横に一緒
                if( arr[0].first == arr[1].first && arr[1].first == arr[2].first ){
                    ans = "Yes";
                } 
                //tate
                if( arr[0].second == arr[1].second && arr[1].second == arr[2].second){
                    ans = "Yes";
                } 
                //斜め
                double one = (double)(arr[1].second - arr[0].second )/(arr[1].first - arr[0].first);
                double two = (double)(arr[2].second - arr[1].second)/(arr[2].first - arr[1].first);
                if( one == two ) {
                    ans = "Yes";
                }
            }
        }
    }
    cout << ans << endl;
}
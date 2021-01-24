#include <bits/stdc++.h>
using namespace std;

void add_score(vector<int> &point_arr, char c){
    if(c == 'A' )point_arr[0]++;
    else if(c == 'T' ) point_arr[1]++;
    else if(c == 'C') point_arr[2]++;
    else if(c == 'G') point_arr[3]++;
}

int main(){
    int N; cin >> N; 
    string S; cin >> S;
    int ans = 0;

    for(int i=0; i<N; ++i){
        //0 : a, 1:t, 2:c , 3:g に対応
        vector<int> a(4, 0);
        for(int j=i; j<N; ++j){
            add_score(a, S[j]);
            if(a[0] == a[1] && a[2] == a[3]){
                ans++;
            }
        }
    }

    cout << ans << endl;
}
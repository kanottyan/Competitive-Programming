#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;
    int len = S.size();

    string rs = S;
    reverse(rs.begin(), rs.end());

    string S_left;
    for(int i=0; i<(len-1)/2; ++i){
        S_left += S[i];
    }
    string S_left_r = S_left;
    reverse( S_left_r.begin(), S_left_r.end() );
    

    string S_right;
    for(int i=(len+3)/2 -1; i<len; ++i){
        S_right += S[i];
    }
    string S_right_r = S_right;
    reverse(S_right_r.begin(), S_right_r.end());


    string ans = "No";
    if(S == rs){
        if( S_left_r == S_left && S_right == S_right_r){
            ans = "Yes";
        }
    }

    cout << ans << endl;
}
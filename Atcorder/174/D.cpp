#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main(){
    int N; cin >> N;
    string s; cin >> s;


    int left_idx = 0;
    int right_idx = N-1;

    int ans = 0;
    while(left_idx != right_idx){
        if( s[right_idx] == 'W' ){
            right_idx--;
        }else{
            //if right == R
            if( s[left_idx] == 'W'){
                swap(s[left_idx], s[right_idx]);
                ans++;
                right_idx--;
            }else{
                left_idx++;
            }
        }
    }

    cout << ans << endl;
}
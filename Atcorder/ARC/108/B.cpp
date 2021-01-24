#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    int N; cin >> N;
    string s; cin >> s;

    int ans = N;
    vector<char> fox_arr;
    if(s[0] == 'f') fox_arr.push_back('f');

    for(int i=1; i<N; ++i){
        if(s[i] != 'f' && s[i] != 'o' && s[i] != 'x'){
            fox_arr.clear();
        }else{
            if(s[i] == 'f'){
                fox_arr.push_back(s[i]);
            }else if(s[i] == 'o' && fox_arr.size() >0 && fox_arr.back() == 'f'){
                fox_arr.push_back(s[i]);
            }else if(s[i] == 'x' && fox_arr.size() >0 && fox_arr.back() == 'o'){
                fox_arr.pop_back();
                fox_arr.pop_back();
                ans -=3;
            }else{
                fox_arr.clear();
            }
        }
    }

    cout << ans << endl;
}
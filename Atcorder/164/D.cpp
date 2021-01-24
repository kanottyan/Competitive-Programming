#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int len = s.size();

    //vector<int> digit_MOD_res(len);
    vector<int> d(len+1);

    int keta = 1;
    d[0] = 0;

    vector<int> count(2019, 0);
    count[0]++;

    for(int i=0; i<len; ++i ){
        int digit = (s[i] - '0');
        //digit_MOD_res[i] = (digit * keta) % 2019;
        //d[i+1] = (d[i] + digit_MOD_res[i]) % 2019;
        int a = (digit * keta) % 2019;
        d[i+1] = (d[i] + a) % 2019;
        keta *= 10;
        keta %= 2019;
        count[d[i+1]]++;
    }

    long long ans =0;
    for(int i=0; i<2019; ++i){
        if(count[i] > 1){
            ans += (count[i] * (count[i]-1) )/2;
        }
    }

    cout << ans << endl; 
    return 0;
}
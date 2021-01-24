#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    string ans;
    if(s.back() == '2' || s.back() == '4' || s.back() == '5' || s.back() == '7' || s.back() == '9'){
        ans = "hon";
    }else if( s.back() == '0' || s.back() == '1' || s.back() == '6' || s.back() == '8' ){
        ans = "pon";
    }else if(s.back() == '3'){
        ans = "bon";
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    string s;
    cin >> s;

    string ans = "Yes";
    if(s == "AAA" || s == "BBB"){
        ans = "No";
    }
    
    cout << ans << endl;
}
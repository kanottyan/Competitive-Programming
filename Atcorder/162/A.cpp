#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string st;
    cin >> st;

    string ans = "No";
    for(int i=0; i< (int)st.size(); ++i){
        if(st[i] == '7') ans = "Yes";
    }

    cout << ans << endl;
}
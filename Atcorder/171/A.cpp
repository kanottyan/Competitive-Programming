#include <iostream>
#include <vector>

using namespace std;

int main(){
    char a;
    cin >> a;

    char ans;
    if(isupper(a)){
        ans = 'A';
    }else{
        ans = 'a';
    }

    cout << ans << endl;
}
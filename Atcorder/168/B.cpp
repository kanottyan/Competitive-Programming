#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int K;
    string S;

    cin >> K;
    cin >> S;

    string ans = "";
    if(S.size() <=K ){
        ans = S;
    }else{
        for(int i=0; i<K; ++i){
            ans += S[i];
        }
        ans += "...";
    }

    cout << ans << endl;
}
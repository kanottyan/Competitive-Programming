#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;

    int ans = 0;
    int tmp = 0;
    for(int i=0; i<S.size(); ++i){
        if(S[i] == 'R'){
            tmp++;
            ans = max(ans, tmp);
        }else{
            tmp  = 0;
        }
    }

    cout << ans << endl;
}
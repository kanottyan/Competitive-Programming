#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string T;
    cin >> T;
    string ans = "";
    

    for(long long i=0; i<T.size(); ++i){
        if(i == 0){
            if(T[i] == '?'){
                if(T.size() == 1){
                    ans += "D";
                }else{
                    if(T[i+1] == 'P'){
                        ans += "D";
                    }else{
                        ans += "P";
                    }
                }
            }else{
                ans += T[i];
            }
        }else if(i == T.size()- 1){
            if(T[i] == '?'){
                if(ans[i-1] == 'P'){
                    ans += "D";
                }else{
                    ans += "D";
                }
            }else{
                ans += T[i];
            }
        }else{
            if(T[i] == '?'){
                if(ans[i-1] == 'P' || T[i+1] == 'P'){
                    ans += "D";
                }else{
                    ans += "P";
                }
            }else{
                ans += T[i];
            }
        }
    }
    cout << ans << endl;
}
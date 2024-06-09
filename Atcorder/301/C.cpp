#include<bits/stdc++.h>

using namespace std;

int main(){
    string S, T;
    cin >> S;
    cin >> T;
    
    bool flag = false;
    do{
        do{
            for(int i=0; i<S.size(); ++i){
                if(S[i] != T[i] && T[i] != '@' && S[i] != '@'){
                    break;
                }
                flag = true;
                if(flag == true){
                    break;
                }
            }
        }while(next_permutation(S.begin(), S.end()));
    }while(next_permutation(T.begin(), T.end()));

    cout << flag << endl;
}

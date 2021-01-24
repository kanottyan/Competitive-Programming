#include<bits/stdc++.h>
#include<string>
using namespace std;


int main(){
    string S, T;
    cin >> S >> T;

    int diff =100000;
    for(int s=0; s<=S.size() - T.size(); ++s){
        int tmp = 0;

        for(int t=0; t<T.size(); ++t){
            if(S[s+t] != T[t]){
                tmp++;
            }
        }
        diff = min(diff, tmp);
    }

    cout << diff << endl;
}
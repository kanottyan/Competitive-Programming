#include <iostream>
#include <vector>

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    bool flag = true;
    for(int i=0; i<S.size(); ++i){
        if(S[i] != T[i]) flag = false;
    }


    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
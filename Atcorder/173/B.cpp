#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int status[4];

int main(){
    int N; cin >> N;
    vector<string> s(N);

    for(int i=0; i<N; ++i){
        cin >> s[i];
    }

    for(int i=0; i<N; ++i){
        if(s[i] == "AC"){
            status[0]++;
        }else if(s[i] == "WA"){
            status[1]++;
        }else if(s[i] == "TLE"){
            status[2]++;
        }else if(s[i] == "RE"){
            status[3]++;
        }
    }

    for(int i=0; i<4; ++i){
        if(i == 0){
            cout << "AC x " << status[i] << endl;
        }else if(i == 1){
            cout << "WA x " << status[i] << endl;
        }else if(i == 2){
            cout << "TLE x "<< status[i] << endl;
        }else if(i == 3){
            cout << "RE x " << status[i] << endl;

        }
    }
}
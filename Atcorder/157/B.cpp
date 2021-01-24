#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int bingo[3][3];
bool mark[3][3];

int main(){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            int a; 
            cin >> a;
            bingo[i][j] = a;
        }
    }

    int N; cin >> N;

    for(int n=0; n<N; ++n){
        int b; cin >> b;
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(b == bingo[i][j]) mark[i][j] = true;
            }
        }
    }

    string ans = "No";

    for(int i=0; i<3; ++i){
            if (mark[i][0] == true && 
                mark[i][1] == true && 
                mark[i][2] ==true ){
                    ans = "Yes";
                }
    }

    for(int j=0; j<3; ++j){
            if (mark[0][j] == true && 
                mark[1][j] == true && 
                mark[2][j] ==true ){
                    ans = "Yes";
                }
    }

    if(mark[0][0] == true &&
        mark[1][1] == true &&
        mark[2][2] == true){
            ans = "Yes";
        }

    if(mark[0][2] == true && 
        mark[1][1] == true &&
        mark[2][0] == true){
            ans = "Yes";
        }

    cout << ans << endl;
}
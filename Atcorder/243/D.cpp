#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const long long MAX = pow(10, 18);

int main(){
    long long N, X; cin >> N >> X;
    string S; cin >> S;

    
    bool over_flow = false;
    int layer = 0;
    for(int i=0; i<S.size(); ++i){
        char c = S[i];
        if(!over_flow){
            if( c == 'U'){
                X = X/2;
            }else if(c == 'L'){
                if( (X*2) > MAX ){
                    layer = 1;
                    over_flow = true;
                }else{
                    X = (X*2);
                }
            }else{
                if( (X*2)+1 > MAX ){
                    layer = 1;
                    over_flow = true;
                }else{
                    X = (X*2)+1;
                }
            }
        }else{
            // if overflow we know we will return to the node eventually, so we only counting the node whichs will return to layer 0;
            if( c == 'U' ){
                layer--;
                if(layer == 0){
                    over_flow = false;
                }
            }else{
                layer++;
            }
        }
    }

    cout << X << endl;

    return 0;
}
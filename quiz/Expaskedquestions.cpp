#include <bits/stdc++.h>
using namespace std;


int main(){
    int N = 6;
    vector<int> s;

    for(int i=0; i<6; ++i){
        s.push_back(1<<i);
    }

    int n = N-1;
    while(n--){
        vector<int> ns;
        for(int i=0; i<6; ++i){
            for(int num : s){
                ns.push_back( (num|(1<<i)) );           
            } 
        }
        s = ns;
    }

    int sum = 0;
    for(int e: s){
        sum += __builtin_popcount(e);
    }

    double ans = (double)sum/(double)pow(6,N);
    cout << ans << endl;
}
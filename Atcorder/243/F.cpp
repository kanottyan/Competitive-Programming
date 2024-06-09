#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int pairs(int k, vector<int> arr) {
    
    map<map<int, int>, int> m;
    
    for(int i=0; i<arr.size(); ++i){
        map<int, int> candidate1, candidate2;
        candidate1.insert({arr[i], arr[i]+k});
        
        if(m.count(candidate1) > 0){
            m[candidate1]++;
        }else{
            m[candidate1] = 0;
            cout << arr[i] << ",,,," << arr[i]+k << endl;
        }
        
        if( arr[i] -k >=0){
            if(m.count(candidate2) > 0){
                m[candidate2]++;
            }else{
                m[candidate2] = 0;
            }
        }
    }
    
    for(auto c : m){
        for(auto p : c.first ){
            cout << p.first << ", " << p.second;        
        }
        cout << ": " << c.second << endl;
    }
    return 0;
}

int main(){
    vector<bool> s = {true, true, false, false};
    sort(s.begin(), s.end());
    int hist[20] = {0};
    int cnt = 0;
    do{
        int tmp = 0;
        int prev = -1;
        for(bool b : s){
            int cur = b;
            if(cur != prev) tmp++;
            prev = cur;
            cout << b << " ,";
        }
        cout << endl;
        cnt++;
        hist[tmp]++;
    }while(next_permutation(s.begin(), s.end() ) );

    double exp = 0;
    for(int i=0; i<20; ++i){
        exp += (double)i*((double)hist[i] /(double)cnt) ;
    }
    cout << exp << endl;

}

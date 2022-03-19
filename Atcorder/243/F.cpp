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

    cout << atomic<>.is_lock_free() << endl;
    
}

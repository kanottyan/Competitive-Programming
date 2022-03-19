#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {2,7, 3, 2, 6, 5,1 ,2 , 4, 7, 6 ,3, 4, 2, 3, 2, 1};
    int k = 6;
    int n = v.size();

    deque<int> dq;

    for(int i=0; i<n; ++i){
        // graduates the biggest number
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && v[i] >= v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }


    return 0;
}

    for(int c_num=1; c_num<s.size(); ++c_num){
        // how many letters to use
        map<map<char, int>, int> mp;          
        for(int i=0; i<=s.size() - c_num; ++i){
            map<char, int> tmps;
            for(int j=i; j<i+c_num; ++j){
                tmps[s[j]]++;            
            }
            mp[tmps]++; 
        }
        
        for(auto m : mp){
                ans += m.second*(m.second-1)/2;
        }
    }    
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    
    int N, M; cin >> N >> M;
    vector<vector<int>>  ga(N, vector<int>());
    vector<vector<int>>  gb(N, vector<int>());

    for(int i=0; i<M; ++i){
        int a, b; 
        cin >> a >> b;
        a--; b--;
        
        ga[a].push_back(b);
        ga[b].push_back(a);
    }

    for(int i=0; i<M; ++i){
        int a, b; 
        cin >> a >> b;
        a--; b--;
        gb[a].push_back(b);
        gb[b].push_back(a);
    }
    
    vector<int> target(N);
    for(int i=0; i<N; ++i) target[i] = i;

    bool flag2= false;
    do{
        vector<vector<int>>  new_gb(N, vector<int>());
        map<int, int> m;
        for(int i=0; i<N; ++i){
            m[i] = target[i];
        }

        for(int i=0; i<N; ++i){
            int s = gb[i].size();
            for(int j=0; j<s; ++j){
                new_gb[m[i]].push_back(m[gb[i][j]]);
            }
        }

        bool flag = true;
        for(int i=0; i<N; ++i){
            set<int> s1;
            set<int> s2;
            int a = new_gb[i].size(); 
            int b = ga[i].size();
            if( a != b){
                flag = false;
                continue;
            } 
            for(int j=0; j<new_gb[i].size(); ++j){
                s1.insert(ga[i][j]);
                s2.insert(new_gb[i][j]);
            }
            if(s1 != s2) flag= false;
        }

        if(flag) {
            flag2 = true;
            break;
        }

    } while(next_permutation(target.begin(), target.end()));


    if(flag2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    // vector<int> target(N);
    // for(int i=0; i<N; ++i){
    //     target[i] = gb[i].size();
    // }

    // bool flag = false;
    // do{
    //     bool flag2 = true;
    //     for(int i=0; i<N; ++i){
    //         if(target[i] != expected[i]) flag2 =false;
    //     }
    //     if(flag2){
    //         flag = true;
    //         break;
    //     }
    // } while(next_permutation(target.begin(), target.end()));

    // if(flag){
    //     cout << "Yes" << endl;
    // }else{
    //     cout << "No" << endl;
    // }


    return 0;
}
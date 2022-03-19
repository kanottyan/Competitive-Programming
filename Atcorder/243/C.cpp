#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;

    vector<pair<int, int>> A(N);
    for(int i=0; i<N; ++i){
        int x, y;
        cin >> x >> y;

        A[i] = {x , y};
    }
    string S; cin >> S;


    // y axix, then the most left R and the most right L
    map<int, map<char, int>> m;

    for(int i=0; i<N; ++i){
        int x = A[i].first;
        int y = A[i].second;
        char lr = S[i];
        if(m.count(y) >0){            
            if(m[y].count(lr)){
                if(lr == 'R'){
                    m[y][lr] = min(m[y][lr], x);
                }else{
                    m[y][lr] = max(m[y][lr], x);
                }
            }else{
                m[y][lr] = x;
            }
        }else{
            m[y][lr] = x;
        }
    }

    bool flag = false;
    for(auto p : m){
        if( p.second.count('R') >0 && p.second.count('L') > 0){
            if( p.second['L'] - p.second['R'] >= 0) flag = true;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
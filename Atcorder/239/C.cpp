#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int main(){

    set<pair<int, int>> s1;
    set<pair<int, int>> s2;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i=0; i<8; ++i){
        int x = x1 + dx[i];
        int y = y1 + dy[i];
        s1.insert({x, y});

        x = x2 + dx[i];
        y = y2 + dy[i];
        s2.insert({x, y});
    }

    bool flag = false;
    for(auto p: s1){
        if(s2.count(p)) flag = true;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
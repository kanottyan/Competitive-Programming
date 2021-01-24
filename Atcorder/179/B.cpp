#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> dices(N);

    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        dices[i] = {a, b};
    }

    bool flag = false;
    for(int i=0; i<=N-3; ++i){
        int D1 = dices[i].first;
        int D2 = dices[i].second;

        int D21 = dices[i+1].first;
        int D22 = dices[i+1].second;

        int D31 = dices[i+2].first;
        int D32 = dices[i+2].second;

        if(D1 == D2 && D21 == D22 && D31 == D32){
            flag = true;
        } 
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
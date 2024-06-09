#include <bits/stdc++.h>

using namespace std;


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v(M);
    for(int i=1; i<=M; ++i){
        v[i-1] = i;
    }

    set<vector<int>> s;

    do{
        bool flag = true;
        vector<int> tmp;

        for(int i=0; i<N; ++i){
            tmp.push_back(v[i]);
        }

        if(s.count(tmp) != 0) continue;


        for(int i=0; i<N-1; ++i){
            if(tmp[i+1] < tmp[i]) flag= false;
        }
        if(flag){
            s.insert(tmp);
            for(int i=0; i<N; ++i){
                cout << tmp[i] << " ";
            }
            cout << endl;
        }

    }while(next_permutation(v.begin(), v.end()));

}
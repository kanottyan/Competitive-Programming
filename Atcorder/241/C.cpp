#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int N; cin >> N;
    vector<string> S(N);

    for(int i=0; i<N; ++i){
        cin >> S[i];
    }

    bool flag = false;
    //tate
    for(int j=0; j<N; ++j){
        map<char, int> m;        
        for(int i=0; i<N; ++i){
            if(S[i][j] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }

            if(i >= 5){
                m[S[i-5][j]]--;
            }

        }
    }

    //yoko
    for(int i=0; i<N; ++i){
        map<char, int> m;        
        for(int j=0; j<N; ++j){
            if(S[i][j] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }

            if(j >= 5){
                m[S[i][j-5]]--;
            }
        }
    }

    //naname  migi 1
    for(int i=0; i<N-5; ++i){
        map<char, int> m;        
        int j = 0;
        int t = i;
        while(t <N && j < N){
            if(S[t][j] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }

            if(j >= 5 ){
                m[S[t-5][j-5]]--;
            }
            t++;
            j++;
        }
    }

    // naname migi 2
    for(int j=0; j<N-5; ++j){
        map<char, int> m;        
        int i =0;
        int y = j;
        while(i <N && y < N){
            if(S[i][y] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }
            if(i >= 5){
                m[S[i-5][y-5]]--;
            }
            i++;
            y++;
        }
    }

    // naname hidari 1
    for(int j=5; j<N; ++j){
        map<char, int> m;        
        int i =0;
        int y = j;
        while(i <N && y >= 0){
            if(S[i][y] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }
            if(i >= 5){
                m[S[i-5][y+5]]--;
            }
            i++;
            y--;
        }
    }


    // naname hidari 2
    for(int i=0; i<N-5; ++i){
        map<char, int> m;      
        int j = N-1;
        int t=i;
        int cnt = 0;
        while(t <N && j >= 0){
            cnt++;
            if(S[t][j] == '#'){
                m['#']++;
            }else{
                m['.']++;
            }
            if(m['#'] >= 4){
                flag = true;
                break;
            }
            if(cnt >= 6){
                m[S[t-5][j+5]]--;
            }
            t++;
            j--;
        }
    }


    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}
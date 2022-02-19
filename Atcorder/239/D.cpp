#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    vector<bool> isprime(201);
    isprime[0] = false;
    isprime[1] = false;
    for(int i=2; i<201; ++i){
        isprime[i] = true;
    }

    for(int i=2; i<=200; ++i){
        if(!isprime[i]) continue;
        for(int j=i*2; j<=200; j += i){
            isprime[j] = false;
        }
    }

    int A, B, C, D; cin >> A >> B >> C >> D;
    map<bool, int> m;
    m[true] = 0;
    m[false] = 0;

    for(int i=A+C; i<=A+D; ++i){
        if(isprime[i] == true){
            m[true]++;
        }else{
            m[false]++;
        }
    }

    bool takahashi = false;
    
    if(m[true] == 0){
        takahashi = true;
    }else{

        for(int i=A+1; i<=B; ++i){
            m[isprime[i+C-1]]--; 
            m[isprime[i+D]]++;
            
            if(m[true] == 0){
                takahashi = true;
            }
        }
    }


    if(takahashi){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }

}
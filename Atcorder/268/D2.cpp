#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){

    int N; cin >> N;
    int M; cin >> M;

    int res = 16 - N;

    vector<string> vs(16, "");
    for(int i=0; i<N; ++i){
        cin >> vs[i]; 
    }

    unordered_set<string> us;
    for(int i=0; i<M; ++i){
        string s; cin >> s;
        us.insert(s);
    }
    
    sort(vs.begin(), vs.end());

    do{
        for(int bit=0; bit<(1<<res); ++bit){
            string candidate = "";
            bool good = true;
            int shift = 0;
            int cnt = 0;
            bool pass = false;
            

            for(int i=0; i<res; ++i){
                if(candidate.size() > 0 && candidate.front() == '_'){
                    pass = true;
                    break;
                }
                if(i >0){
                    if(vs[i+shift] != "" && candidate.back() == '_'){
                        candidate += vs[i+shift];
                        shift++;
                        cnt++;
                    }
                }else{
                    if(vs[0] != ""){
                        candidate += vs[0];
                        shift++;
                        cnt++;
                    }
                }

                if((bit >> i) & 1){
                    candidate += "_";
                }
            }
            if(pass) continue;

            if(N - shift >= 2) continue;
            if(N - shift == 1){
                if(candidate.back() == '_'){
                    candidate += vs[15];
                }
            }

            if(cnt != N){
                continue;
            }

            if(candidate == ""){
                continue;
            }

            if(candidate.front() == '_'){
                continue;
            }
            
            if(candidate.back() == '_'){
                continue;
            }
            
            if(candidate.size() >16){
                continue;
            }

            if( us.count(candidate) == 0 ){
                cout << candidate << endl;
                return 0;
            }
        }
    }while(next_permutation(vs.begin(), vs.end())); 

    cout << -1 << endl;
    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

set<string> bad_case;

int main(){
    bad_case.insert("0");
    bad_case.insert("1");
    bad_case.insert("2");
    bad_case.insert("3");
    bad_case.insert("4");
    bad_case.insert("5");
    bad_case.insert("6");
    bad_case.insert("7");
    bad_case.insert("8");
    bad_case.insert("9");


    int N; cin >> N;
    int M; cin >> M;

    vector<string> vs(8, "");
    for(int i=0; i<N; ++i){
        cin >> vs[i]; 
    }
    for(int i=N; i<=7; ++i){
        vs[i] = to_string(i);
    }

    unordered_set<string> us;
    for(int i=0; i<M; ++i){
        string s; cin >> s;
        us.insert(s);
    }

    sort(vs.begin(), vs.end());
    

    do{
        for(int bit=0; bit<(1<<7); ++bit){
            string candidate = "";
            string candidate2 = "";
            int cnt = 0;
            int cnt2 = 0;

            for(int i=0; i<7; ++i){
                if(i > 0){
                    if(bad_case.count(vs[i]) == 0){
                        if(candidate.back() != '_'){
                            candidate += "";
                        }else{
                            candidate += vs[i];
                            cnt++;
                        }
                        if(candidate2.back() != '_'){
                            candidate2 += "_";

                        }else{
                            candidate2 += vs[i];
                            cnt2++;
                        }
                    }else{
                        candidate += "";
                        candidate2 += "_";
                    }
                }else{
                    if(bad_case.count(vs[i]) == 0 ){
                        candidate += vs[i];
                        candidate2 += vs[i];
                        cnt++;                        
                        cnt2++;
                    }
                }
                
                if((bit >> i) & 1){
                    candidate += "_";
                    candidate2 += "_";
                }

            }

            if(candidate == ""){
                continue;
            }

            if(candidate.front() == '_'){
                continue;
            }

            if(candidate.back() != '_' && bad_case.count(vs[7]) == 0 ){
                continue;
            }

            if(bad_case.count(vs[7]) == 0 ){
                candidate += vs[7];
                cnt++;
            }

            if(cnt != N){
                continue;
            }
            
            if(candidate.back() == '_'){
                continue;
            }

            if(candidate.size() < 3){
                continue;
            }

            if(candidate.size() >16){
                continue;
            }

            if( us.count(candidate) == 0 ){
                cout << candidate << endl;
                return 0;
            }

            if(candidate2 == ""){
                continue;
            }

            if(candidate2.front() == '_'){
                continue;
            }

            if(candidate2.back() != '_' && bad_case.count(vs[7]) == 0 ){
                continue;
            }

            if(bad_case.count(vs[7]) == 0 ){
                candidate2 += vs[7];
                cnt2++;
            }

            if(cnt2 != N){
                continue;
            }
            
            if(candidate2.back() == '_'){
                continue;
            }

            if(candidate2.size() < 3){
                continue;
            }
            if(candidate2.size() >16){
                continue;
            }

            if( us.count(candidate2) == 0 ){
                cout << candidate2 << endl;
                return 0;
            }


        }
    }while(next_permutation(vs.begin(), vs.end())); 

    cout << -1 << endl;
    return 0;
}
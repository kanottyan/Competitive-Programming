#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(){
    queue<char> q;
    string S; cin >> S;
    int K; cin >> K;
    int avaialble_dot = K;

    int idx = 0;
    int ans = 0;
    while(true){
        while(S[idx] == 'X'){
            q.push(S[idx]);
            ans = max(ans, (int)q.size());
            idx++;
        }

        ans = max(ans, (int)q.size());
        if(idx >= S.size()) break;
        //susumeruaida
        while( avaialble_dot > 0){
            if(idx >= S.size()) break;

            if(S[idx] == 'X'){
                q.push(S[idx]);
                idx++;
                ans = max(ans, (int)q.size());
            }else{
                q.push(S[idx]);
                avaialble_dot--;
                idx++;
                ans = max(ans, (int)q.size());
            }
        }

        ans = max(ans, (int)q.size());
        if(idx >= S.size()) break;


        while(S[idx] == 'X'){
            q.push(S[idx]);
            ans = max(ans, (int)q.size());
            idx++;
        }

        ans = max(ans, (int)q.size());
        if(idx >= S.size()) break;

        //susumenakunattara
        if(q.size() >0 ){
            if( q.front() != '.' ){
                char c = q.front(); q.pop();
                ans = max(ans, (int)q.size());
            }else{
                char c= q.front(); q.pop();
                avaialble_dot++;
                ans = max(ans, (int)q.size());
            }
        }else{
            idx++;
        }
    }
        

    ans = max(ans, (int)q.size());

    cout << ans << endl;
    return 0;
}
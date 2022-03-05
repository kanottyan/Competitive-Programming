#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

string S; 

string transform(char c){
    if(c == 'A'){
        return "BC";
    }
    if(c == 'B'){
        return "CA";
    }
    if(c == 'C'){
        return "AB";
    }
    return "";
};

char solve(long long t, long long k){
    stack<int> q;

    while(k > 1 && t > 0){
        q.push((k+1)%2);
        k = (k+1)/2;
        t--;
    }

    char cur;
    if(t > 0){
        cur = 'A' + (S[0] - 'A' + t)%3;
    }else{
        cur = S[k-1];
    }
    char nc = cur;
    while( !q.empty() ){
        string ns = transform(nc);
        nc = ns[q.top()];
        q.pop();
    }

    return nc;
};

int main(){
    cin >> S;
    int Q; cin >> Q;

    while(Q--){
        long long t, k; cin >> t >> k;
        char ans = solve(t, k);
        cout << ans << endl;
    }

    return 0;
}
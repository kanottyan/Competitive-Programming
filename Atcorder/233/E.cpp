#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<int> res;


int main(){
    string X; cin >> X;
    int s = X.size();
    vector<int> score(s+1);
    res.resize(s+1);

    for(int i=0; i<X.size(); ++i){
            score[i+1] = score[i] + int(X[i] - '0');

    }


    for(int i=0; i<s; ++i){
        // score is from bottom 
        int target = score[s-i];
        queue<int> q;

        while(target > 0){
            int tmp = target %10;
            target = target/10;
            q.push(tmp);
        }

        int idx = 0;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            int tot = res[s-i-idx] +n;
            if(tot >= 10){
                res[s-i-idx-1] += tot/10;
            }
            res[s-i-idx] = tot%10;
            idx++;
        }
    }

    bool init_zero = true;
    for(int i=0; i<res.size(); ++i){
        if(init_zero && res[i] == 0) continue;
        init_zero = false;
        cout << res[i] ;
    }

    cout << endl;

    return 0;
}
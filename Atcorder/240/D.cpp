#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){
    int N; cin >> N;
    //first one is num, second one is the counter
    stack<pair<int, int>> s;

    vector<int> a(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    s.push({a[0], 1});
    cout << s.size() << endl;
    int ans = 1;

    for(int i=1; i<N; ++i){

        if(s.empty()){
            s.push({a[i], 1});
            ans++;
            cout << ans << endl;
            continue;
        }
        int top_num = s.top().first;
        int top_counter = s.top().second;

        if(a[i] == top_num){
            s.top().second += 1;
            ans++;
            if(s.top().second == s.top().first){
                ans -= s.top().first;
                s.pop();
            }

        }else{
            s.push({a[i], 1});
            ans++;
        }

        cout << ans << endl;
    }



    return 0;
}
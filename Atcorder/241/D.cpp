#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){

    multiset<long long> s;

    int Q; cin >> Q;
    s.insert(-1);
    s.insert(__LONG_LONG_MAX__);

    while(Q--){
        int idx; cin >> idx;
        long long x, k; 
        if(idx == 1){
            long long x; cin >> x;
            s.insert(x);
        }else if(idx == 2){            
            cin >> x >> k;
            auto it = s.upper_bound(x);
            bool flag = false;
            while(k){
                it--;
                if(*it == -1){
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
                k--;
            }
            
            if(!flag) cout << *it << endl;
        }else{
            cin >> x >> k;
            auto it = s.lower_bound(x);
            bool flag = false;
            k -= 1;

            if(*it == LONG_LONG_MAX ){
                cout << -1 << endl;
                flag = true;
            }
            if(!flag){
                while(k){
                    it++;
                    if(*it == LONG_LONG_MAX){
                        cout << -1 << endl;
                        flag = true;
                        break;
                    }
                    k--;
                }
            }
            if(!flag) cout << *it << endl;
        }
    }


    return 0;
}
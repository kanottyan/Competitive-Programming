#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    long long N, K; cin >> N >> K;

    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    set<long long> s;
    queue<long long> q; //store one cycle length

    bool is_cycle = false;
    long long sum = 0;
    int cycle_start_idx = 0;

    while(!is_cycle && s.size() != K ){
        int idx = sum%N;
        if( s.count(idx) > 0 ){
            is_cycle = true;
            cycle_start_idx = idx;
            break;
        }else{
            s.insert(idx);
            sum += A[idx];
            q.push(idx);
        }
    }

    long long cycle_sum = 0;
    long long ans = 0;
    if(is_cycle){
        //check the cycle
        while(q.front() != cycle_start_idx){
            ans += A[q.front()];
            q.pop();
            K--;
        }
    }
    

    queue<long long> tmp = q;
    while(!tmp.empty()){
        cycle_sum +=  A[tmp.front()];
        tmp.pop();
    }


    if(!is_cycle){
        ans = cycle_sum;
    }else{
        ans += cycle_sum*(K/q.size());
        K %= q.size();
        while(K--){
            ans += A[q.front()];
            q.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
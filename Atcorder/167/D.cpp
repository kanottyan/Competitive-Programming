#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main(){
    map<int, int> m;
    int N;
    long long K;

    cin >> N >> K;

    m[0] =1;
    for(int i=0; i<N; ++i){
        int dest;
        cin >> dest;
        m[i+1] = dest;
    }

    queue<long long> hist; // 訪問履歴
    set<long long> cycle; // cycle detection
    long long cycle_start = -1;


    hist.push(1);
    cycle.insert(1);
    long long ans = m[1];

    while(true){
        if( cycle.count(ans) > 0){
            cycle_start = ans;
            break;
        }
        // if no cycle case
        if(ans == 0){
            break;
        }
        hist.push(ans);
        cycle.insert(ans);
        ans = m[ans];
    }

    long long count = 0;
    while(cycle_start > 0){
        long long num = hist.front();
        if(num != cycle_start){
            count++;
            hist.pop(); 
            ans = m[num];
        }else{
            break;
        }
    }

    if( cycle_start > 0){
        if( K < count ){
            ans = m[0];
            for(int i=0; i<K; ++i){
                ans = m[ans];
            }

        }else{
            //cycle mod calculation
            K = K - count;
            long long cycle_size = hist.size();
            long long idx = K%cycle_size;
            for(long long i=0; i<idx; ++i){
                ans = m[ans];
        }

        }
    }else{
        for(int i=0; i<=K; ++i){
            ans = m[ans];
        }    
    }

// 5 5
// 2 3 4 5 6


    cout << ans << endl;
}
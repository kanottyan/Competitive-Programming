#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const int END = 1000100;
vector<int> arr(1000100, 1001001);

int main(){
    int a, N; cin >> a >> N;

    auto swap_back_to_front = [](int n){
        int res = n / 10;
        int delta = 1;
        while (delta <= res) delta *= 10;
        return (n % 10) * delta + res;
    };

    // 1st: cnt, second idx
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;

    pq.emplace(0, 1);

    while(!pq.empty()){
        int cnt = pq.top().first;
        int factor = pq.top().second;
        pq.pop();

        for(long long i=factor; i<END; i=i*a){
            arr[i] = min(arr[i], cnt);
            cnt++;
            if(i >= 11 && i%10 != 0){ 
                int swaped_num = swap_back_to_front(i);
                if(swaped_num >= END) continue;
                if(cnt < arr[swaped_num]){
                    pq.emplace(cnt, swaped_num);
                }
            }
        }
    }

    if(arr[N] == 1001001 ) arr[N] = -1;
    cout << arr[N] << endl;

    return 0;
}
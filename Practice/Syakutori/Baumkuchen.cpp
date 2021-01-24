//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0600

#include <iostream> 
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N*2);// 環状の数列を扱うときは二週確保はよくやる
    long long total =0; //バームクーヘンの全体のサイズ
    for(int i=0; i<N; ++i) cin >> a[i],a[i+N] = a[i], total += a[i];

    /*二分探索*/
    long long low = 0, high = 1LL<<60;
    while(high - low > 1){
        /*3ピースともmid以上にできるかを判定*/
        long long mid = low + (high - low) /2;
        /*しゃくとり法によって、切れ目からmid以上になる最小区間をきめる*/
        vector<int> Next(N, -1);
        vector<long long> Size(N, -1);

        int right = 0;
        long long sum = 0;
        for(int left=0; left <N; ++left){
            while(right < N*2 && sum < mid){
                sum+= a[right];
                ++right;
            }
            if(sum >=mid){
                Next[left] = right;
                Size[left] = sum;
            }
            if(right == left) ++right;
            else sum-= a[left];
        }

        /*check*/
        bool ok = false;
        for(int i=0; i<N; ++i){
            /* piece 1 */
            int ni = Next[i];
            if(ni == -1) continue;
            if(Size[i] >= total) continue;

            /* piece 2 */
            ni %= N;
            int nni = Next[ni];
            if(nni == -1) continue;

            /* if the rest is greater than mid then ok */
            if(total - Size[i] - Size[ni] >= mid) ok = true;
        }

        if(!ok) high = mid;
        else low = mid;
    }

    cout << low << endl;

    

}
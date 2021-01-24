//kazueage
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,Q;
    cin >> n >> Q;
    vector<long long> a(n);

    for(int i=0; i<n; ++i) cin >> a[i];

    /*process Q queries */
    for(int i=0; i<Q; ++i){
        int q;
        cin >> q;
        long long res = 0;

        /* 区間の左端 left で場合分け */
        int right = 0; // 毎回 right を使い回すようにする
        long long sum = 0;  // sum も使い回す
        for (int left = 0; left < n; ++left) {

            /* sum に a[right] を加えても大丈夫なら right を動かす */
            while (right < n && sum + a[right] <= q) {
                sum += a[right];
                ++right;
            }
            /* break した状態で right は条件を満たす最大 */
            res += (right - left);

            /* left をインクリメントする準備 */
            if(left == right) right++;// right が left に重なったら right も動かす
            else sum -= a[left];

        }

        // for(int left=0; left<n; ++left){
        //     int sum = 0;
        //     sum += a[left];
        //     for(int right=left; right<n; ++right){
        //         if(right - left != 0){
        //             sum += a[right];
        //         }
        //         if(sum <= q){
        //             count++;
        //         }
        //     }
        // }
        cout << res << endl;
    }
}
//sample input
// 6 5
// 1 2 3 4 5 6
// 6 9 12 21 15

// //output
// 9
// 12
// 15
// 21
// 18

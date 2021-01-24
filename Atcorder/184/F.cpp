#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
const long long INF = 1LL << 60;

int main(){
    int N; cin >> N;
    long long T; cin >> T;
    vector<long long> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    vector<long long> W1(1LL<<N/2);
    vector<long long> W2(1LL<<(N- N/2));

    //前半半分全列挙
    for(int bit=0; bit<(1LL<<N/2); ++bit){
        long long sum = 0;
        for(int i=0; i<N/2; ++i){
            if((bit >> i)&1) sum += A[i];
        }
        W1[bit] = sum;
    }

    //後半半分全列挙
    for(int bit=0; bit<(1LL<<(N-N/2)); ++bit){
        long long sum = 0;
        for(int i=0; i<(N - N/2); ++i){
            if((bit >> i)&1) sum += A[i+N/2];
        }
        W2[bit] = sum;
    }

    long long ans = 0;
//    W1.push_back(INF);
//    W2.push_back(INF);
    //ソート
    sort(W1.begin(), W1.end());
    sort(W2.begin(), W2.end());

    //答えを二分探索
    for(long long bit=0; bit<(1LL<<N/2); ++bit){
        long long tmp;
        long long res = T - W1[bit];
        int pos = distance( W2.begin(), lower_bound( W2.begin(), W2.end(), res ));
        if( W2[pos] != res ) pos = pos - 1;
        tmp = W1[bit] + W2[pos];
        if( tmp > ans && tmp <= T ) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}

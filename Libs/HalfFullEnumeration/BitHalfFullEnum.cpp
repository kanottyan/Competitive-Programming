//https://qiita.com/e869120/items/25cb52ba47be0fd418d6#5-4-別の視点からの半分全列挙

// N 個の硬貨があります。番号 i の硬貨は Ai 円です。
// 硬貨の選び方は 2^N 通りありますが、
// その中で合計価格が丁度 X 円となる選び方は存在するでしょうか。
// 制約：1≤N≤40,1≤X,Ai≤108

#include <iostream>
#include <algorithm>

using namespace std;

long long N, X, A[40];
long long W1[1 << 20], W2[1<<20];
bool flag = false;


int main(){
    cin >> N >> X;
    for(int i=0; i<N; ++i) cin >> A[i];

    //前半　N/2個[0-N/2)をbit全探索で全列挙
    for(int bit=0; bit<(1<<(N/2)); ++bit ){
        long long sum = 0;
        for(int i = 0; i< (N/2); i++){
            if( (bit >> i)&1 ) sum += A[i];
        }
        W1[bit] = sum;
    }

    //後半　N- N/2個[N/2-N)をbit全探索で全列挙
    for(int bit=0; bit<(1<< (N-(N/2))); ++bit){
        long long sum = 0;
        for(int i = 0; i<(N-(N/2)); i++){
            if( (bit >> i)&1 ) sum += A[i+ N/2];
        }
        W2[bit] = sum;
    }


    //ソートした上で半分全列挙
    sort(W1, W1 + (1 << (N/2)));
    sort(W2, W2 + (1 << (N - N/2)));

    for(int bit=0; bit<(1<<(N/2)); ++bit){
        long long rem = X - W1[bit];
        int pos1 = lower_bound(W2, W2+ (1 << (N - N/2)), rem) - W2;
        if(W2[pos1] == rem) flag = true;
    }

    if(flag == true ) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
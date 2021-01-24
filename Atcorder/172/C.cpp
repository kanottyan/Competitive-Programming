#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int main(){
    long long N, M, K;
    cin >> N >> M >>K;

    vector<long long> A(N);
    vector<long long> B(M);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<M; ++i) cin >> B[i];

    vector<long long> cumsumA(N+1);
    cumsumA[0] = 0; 
    vector<long long> cumsumB(M+1);
    cumsumB[0] = 0;
    for(int i=1; i<=N; ++i) cumsumA[i] = cumsumA[i-1] + A[i-1];
    for(int i=1; i<=M; ++i) cumsumB[i] = cumsumB[i-1] + B[i-1];

    long long ans = 0;
    long long b_p = M;
    
    for(long long i=0; i<=N; ++i){
        long long tmpk = K - cumsumA[i];
        if(tmpk >= 0){
            while( cumsumB[b_p] > tmpk && b_p >=0 ){
                b_p--;
            }
            ans = max(ans, i + b_p);
        }
    }

    cout << ans << endl;
}

// int main(){
//     long long N, M;
//     cin >> N >> M;
//     long long K;
//     cin >> K;

//     vector<long long> A(N+10);
//     vector<long long> B(M+10);

//     for(long long i=0; i<N; ++i) cin >> A[i];
// //    reverse(A.begin(), A.end());
//     for(long long i=0; i<M; ++i) cin >> B[i];
//    reverse(B.begin(), B.end());
    // stack<long long> sA;
    // for(long long i=0; i<N; ++i){
    //     sA.emplace(A[i]);
    // }
    // stack<long long> sB;
    // for(long long i=0; i<M; ++i){
    //     sB.emplace(B[i]);
    // }

    // while(true){
    //     if(!sA.empty()  && !sB.empty()){
    //         long long a = sA.top();
    //         long long b = sB.top();
    //         if(a<b){
    //             if(K - a >= 0){
    //                 sA.pop();
    //                 K -= a;
    //                 ans++;
    //             }else{
    //                 break;
    //             }
    //         }else if(b<a){
    //             if(K - b >= 0){
    //                 sB.pop();
    //                 K -= b;
    //                 ans++;
    //             }else{
    //                 break;
    //             }
    //         }else{

    //         }
    //     }else if(sA.empty() && !sB.empty()){
    //         long long b = sB.top();
    //         if(K - b >= 0){
    //             sB.pop();
    //             K -= b;
    //             ans++;
    //         }else{
    //             break;
    //         }
    //     }else if(!sA.empty() && sB.empty() ){
    //         long long a = sA.top();
    //         if(K - a >= 0){
    //             sA.pop();
    //             K -= a;
    //             ans++;
    //         }else{
    //             break;
    //         }
    //     }else{
    //         break;
    //     }
    // }

//     long long a_p = 0;
//     long long b_p = 0;
//     long long ans =0;

//     while(true){
//         if(a_p >= N && b_p >= M){
//             break;
//         }else if(a_p >=N && b_p < M){
//             if(K - B[b_p] >=0 ){
//                 K -= B[b_p];
//                 b_p++;
//                 ans++;
//             }else{
//                 break;
//             }
//         }else if(a_p < N && b_p >= M){
//             if( K - A[a_p] >= 0){
//                 K -= A[a_p];
//                 a_p++;
//                 ans++;
//             }else{
//                 break;
//             }
//         }else{
//             if(A[a_p] < B[b_p]){
//                 if( K - A[a_p] >= 0){
//                     K -= A[a_p];
//                     a_p++;
//                     ans++;
//                 }else{
//                     break;
//                 }
//             }else if( A[a_p] > B[b_p] ){
//                 if(K - B[b_p] >=0 ){
//                     K -= B[b_p];
//                     b_p++;
//                     ans++;
//                 }else{
//                     break;
//                 }
//             }else{
//                 long long tmp = 0;
//                 long long same = A[a_p];
//                 while(A[a_p] == B[b_p] && a_p < N && b_p < M){
//                     a_p++;
//                     b_p++;
//                     tmp++;
//                 }
//                 if( K- (2*tmp*same) >= 0 ){
//                     ans += tmp;
//                     if(b_p < M && a_p < N){
//                         if(a_p < b_p){
//                             if( K - A[a_p] >= 0){
//                                 K -= A[a_p];
//                                 a_p++;
//                                 ans++;
//                             }else{
//                                 break;
//                             }
//                         }else{
//                             if(K - B[b_p] >=0 ){
//                                 K -= B[b_p];
//                                 b_p++;
//                                 ans++;
//                             }else{
//                                 break;
//                             }
//                         }
//                     }else if(b_p < M && a_p >= N){
//                         if(K - B[b_p] >=0 ){
//                             K -= B[b_p];
//                             b_p++;
//                             ans++;
//                         }else{
//                             break;
//                         }
//                     }else if(b_p >= M && a_p <N){
//                         if( K - A[a_p] >= 0){
//                             K -= A[a_p];
//                             a_p++;
//                             ans++;
//                         }else{
//                             break;
//                         }
//                     }
//                 }else{
//                     long long num = K/same;
//                     ans += num;
//                     break;
//                 }
//             }
//         }
//     }


//     cout << ans << endl;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int main(){
//     int n, k, c;
//     cin >> n >> k >> c;
//     string s;
//     cin >> s;
//     auto getPositions = [&](){
//         vector<int> res;
//         for(int i=0; i < n && res.size() <k;){
//             if(s[i] == 'o') {
//                 res.push_back(i);
//                 i += c+1;
//             }else{
//                 ++i;
//             }
//         }
//         return res;
//     };

//     vector<int> l, r;
//     l = getPositions();
//     reverse(s.begin(), s.end());
//     r = getPositions();
//     for(int i=0; i<k; ++i) r[i] = n-1-r[i];
//     reverse(s.begin(), s.end());

//     //一個前のoの位置を記録
//     //left
//     vector<int> lastL(n+1, -1);
//     for(int i=0; i<k; ++i){
//         lastL[ l[i]+1 ] = i;
//     }
//     for(int i=0; i<n; ++i){
//         if(lastL[i+1] == -1){
//             lastL[i+1] = lastL[i];
//         }
//     }
//     //right
//     vector<int> lastR(n+1, -1);
//     for(int i=0; i<k; ++i){
//         lastR[ r[i] ] = i;
//     }
//     for(int i=n-1; i>=0; --i){
//         if(lastR[i] == -1){
//             lastR[i] = lastR[i] = lastR[i+1];
//         }
//     }

//     for(int i=0; i<n; ++i){
//         if(s[i] == 'x') continue;
//         int li = lastL[i];
//         int ri = lastR[i+1];
        
//         int cnt = 0;
//         if(li != -1) cnt += li + 1;
//         if(ri != -1) cnt += ri + 1;
//         if(li != -1 && ri != -1 && r[ri] - l[li] <= c){
//             cnt--;
//         }
//         if(cnt >= k) continue;
//         printf("%d\n", i+1);
//     }

// }

int main(){
    int N, K , C;
    string S;
    cin >> N >> K >> C;
    cin >> S;

    vector<int> left(N);
    vector<int> right(N);

    int ng_day = 0;
    //left side(左側につめる)
    for(int i=0; i<N; ++i){
        if(i == 0){
            if(S[i] == 'o'){
                left[i] = 1;
                ng_day = i + C;
            } else{
                left[i] = 0;
            } 
        }else{
            if(S[i]  == 'o' && i > ng_day){
                left[i] = left[i-1] + 1;
                ng_day = i + C;
            }else{
                left[i] = left[i-1];
            }    
        }
    }
    
    //right side（右側に詰める）
    for(int i=N-1; i>=0; --i){
        if(i == N-1){
            if(S[i] == 'o' ){
                right[i] = 1;
                ng_day = i - C;
            }else{
                right[i] = 0;
            }
        }else{
            if(S[i] == 'o' && i < ng_day){
                right[i] = right[i+1] + 1;
                ng_day = i - C;
            }else{
                right[i] = right[i+1];
            }
        }
    }

    vector<int> ans;
    for(int i=0; i<N; ++i){
        if(S[i] == 'x') continue;

        //例外:一番右のleftと一番左のrightの感覚がC以下なら、oを一個減らす。
        long long o_num;
        if(i == 0){
            o_num = right[i];
        }else if(i == N-1){
            o_num = left[i];
        }else{
            
            auto left_idx = lower_bound( left.begin(), left.end(), left[i-1]);
            auto left_dist = distance(left.begin(), left_idx);

            // auto right_idx = upper_bound( right.begin(), right.end(), right[i+ 1]);
            // auto right_dist = distance(right.begin(), left_idx);

            o_num = left[i] + right[i];
            if( abs(right[i+1] - left[i-1] ) <= K ) o_num--;
        }

        //もしその日働かなくても、oの数が左右で足りるのなら、働く必要がない。
        if( K > o_num ){
            ans.push_back(i++);
        }
    }

    for(int i=0; i<ans.size(); ++i){
    cout << ans[i] << endl;
    }
}
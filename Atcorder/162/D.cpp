#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);

    for(int i=0; i<n; ++i){
        if(s[i] == 'R') a[i] = 0;
        if(s[i] == 'G') a[i] = 1;
        if(s[i] == 'B') a[i] = 2;
    }

    vector<long long> cnt(3);
    for(int i=0; i<n; ++i){
        cnt[a[i]]++;
    }

    long long ans = 1;
    for(int i=0; i<3; ++i){
        ans *= cnt[i];
    }

    for(int j=0; j<n; ++j){
        for(int i=0; i<j; ++i){
            int k = j + (j - i);
            if(k < n){
                if(a[i] == a[j])continue;
                if(a[i] == a[k])continue;
                if(a[k] == a[j])continue;
                ans--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>

// using namespace std;

// int main(){
//     int N; cin >> N;
//     string st; cin >> st;

//     vector<int> leftR(N);
//     vector<int> leftG(N);
//     vector<int> leftB(N);

//     if(st[0] == 'R'){
//         leftR[0]++;
//     }else if(st[0] == 'G'){
//         leftG[0]++;
//     }else{
//         leftB[0]++;
//     }

//     for(int i=1; i<N; ++i){
//         leftR[i] = leftR[i-1];
//         leftG[i] = leftG[i-1];
//         leftB[i] = leftB[i-1];

//         if(st[i] == 'R'){
//             leftR[i]++;
//         }else if( st[i] == 'G' ){
//             leftG[i]++;
//         }else{
//             leftB[i]++;
//         } 
//     }

//     long long cnt = 0;
//     for(int j=1; j<=(int)st.size()-1; ++j){
//         char mid_char = st[j];

//         for(int i=0; i<j; ++i){
//             char first_char = st[i];
//             int dif = j - i;
//             if(j+dif > N ){
//                 cout << st[j+dif] << endl;
//             }

//             if(first_char == 'R' && mid_char == 'G'){
//                 int tmp = leftB[N-1] - leftB[j];
//                 if( tmp > 0 && j+dif < N &&  st[j+dif] == 'B') tmp--;
//                 cnt += tmp;
//             }else if(first_char == 'R' && mid_char == 'B'){
//                 int tmp = leftG[N-1] - leftG[j];
//                 if( tmp > 0 && j+dif < N && st[j+dif] == 'G') tmp--;
//                 cnt += tmp;                
//             }else if(first_char == 'B' && mid_char == 'R'){
//                 int tmp = leftG[N-1] - leftG[j];
//                 if( tmp > 0 && j+dif < N && st[j+dif] == 'G') tmp--;
//                 cnt += tmp;                
//             }else if(first_char == 'B'&& mid_char == 'G' ){
//                 int tmp = leftR[N-1] - leftR[j];
//                 if( tmp > 0 && j+dif < N && st[j+dif] == 'R') tmp--;
//                 cnt += tmp;
//             }else if(first_char == 'G' && mid_char == 'R'){
//                 int tmp = leftB[N-1] - leftB[j];
//                 if( tmp > 0 && j+dif < N && st[j+dif] == 'B') tmp--;
//                 cnt += tmp;
//             }else if(first_char == 'G' && mid_char == 'B'){
//                 int tmp = leftR[N-1] - leftR[j];
//                 if( tmp > 0 && j+dif < N && st[j+dif] == 'R') tmp--;
//                 cnt += tmp;
//             }

//             // if( first_char != mid_char ){
//             //     for(int k=j+1; k<(int)st.size(); ++k){
//             //         char last_char = st[k];
//             //         if( mid_char != last_char && first_char != last_char && j-i != k-j){
//             //             cnt++;
//             //             //cout << i << j << k << endl;
//             //         }
//             //     }
//             // }
//         }
//     }

//     cout << cnt << endl;
// }

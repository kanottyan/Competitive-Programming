#include <bits/stdc++.h>
using namespace std;

// Ans 1: by bit math
// x+y  equals to (x^y) + (x&y<<1)
int main(){
    int T; cin >> T;

    while(T--){
        long long a, s; cin >> a >> s;
        // the question means 
        // x&y = a, x&y = ((s-(x^y)) >>1)
        // so uf x^y can constitute s-a*2 means this value should be positive,
        // and x^y vs x&y is distinct in each digit, so each digit result should be zero if we take a and
        bool flag = false;
        if(s-a*2 >= 0){
            if(!((s-a*2)&a)) flag = true;
        }

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    return 0;
}



// // Ans2: rec by digit
// map<pair<long long, long long>, bool> m;

// bool rec(long long a, long long s){
//     //if knows the answer then return
//     if(m.count(make_pair(a, s))) return m[make_pair(a, s)];
//     //if it's sum is zero, the n end.(if a ga 1 nara, okasiikoto ninaru)
//     if(s == 0) return m[make_pair(a, s)] = (a == 0);
    
//     //there are for cases for x, y of last digit
//     for(int x=0; x<=1; ++x)for(int y=0; y<=1; ++y){
//         //x ^ y has to be a's last digit.
//         if((a&1) != (x&y)) continue;
//         // sum can not be negative
//         if(s-x-y < 0) continue;
//         //the last digit should be zero after subtraction
//         if((s-x-y)&1) continue;

//         //other case remove the xy, (and kuriage) then do the next remain digits
//         return m[make_pair(a, s)] = rec(a>>1, (s-x-y)>>1);
//     }
//     return m[make_pair(a, s)] = false;
// }

// void solve(){
//     long long a, s; cin >> a >> s;
//     m = map<pair<long long, long long>, bool>();
//     bool ans = rec(a, s);
//     if(ans) cout << "Yes" << endl;
//     else cout << "No" << endl;
// }

// int main(){
//     int T; cin >> T; 
//     while(T--) solve();
//     return 0;
// }

// my idea
// int main(){
//     int T; cin >> T;

//     while(T--){
//         long long a, ss; cin >> a >> ss;
        
//         bool kuriagari = false;
//         bool flag = true;

//         for(long long bit=0; bit<62; ++bit){
//             bool s = (a >> bit)&1LL;
//             bool e = (ss >> bit)&1LL;
//             // and ga 0 nobaai, tyuukan ha 0 nimo 1 nimo nariuru
//             if(!s){
//                 // mosi sum ga 1 nara
//                 if(e){
//                     // kuriagatteta nara, 0 wo irete, kuriagari wo nakusu.
//                     if(kuriagari){
//                         kuriagari = false;
//                     // kuriagette nai nara, sono mama 1
//                     }else{
//                         continue;
//                     }
//                 // mosi sum ga 0 nara,
//                 }else{
//                     // kuriagari ga arubaai ha, 1 wo irete, kuriagari iji.
//                     if(kuriagari){
//                         continue;
//                     // kuriagari ga nai baai ha, 0 irete osimasi
//                     }else{
//                         continue;
//                     }
//                 }
//                 // and ga 1 nobaai, kanarazu tyuukan ha 1 ni naru
//             }else{
//                 // mosi sum ga 1 nara,
//                 if(e){
//                     if(kuriagari){
//                         //kuriagariga arunara, keep sinagara ikeru,
//                         continue;    
//                     }else{
//                         // kuriagarenai naram, muri
//                         flag = false;
//                     }
//                 // mosi sum ga 0 nara
//                 }else{
//                     // kuriaga tte tara dekinai
//                     if(kuriagari){
//                         flag =false;
//                     // kuri agatte nai nara true ni site dekiru
//                     }else{
//                         kuriagari =true;
//                     }
//                 }
//             }
//         }

//         if(kuriagari) flag = false;
//         if(flag) cout << "Yes" << endl;
//         else cout << "No" << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;



int main(){
    string X; cin >> X;
    int N; cin >> N;

    vector<string> S(N);
    for(int i=0; i<N; ++i) cin >> S[i];

    vector<int> pos(26);

    for(int i=0; i<26; ++i){
        pos[X[i]] = i;
    }

    sort(S.begin(), S.end(), [&](const string& s, const string& t){
        int len = min(t.size(), s.size());
        for(int i=0; i<len; ++i){
            if(s[i] != t[i]){
                return pos[s[i]] < pos[t[i]];
            }
        }

        return s.size() < t.size();
    });

    for(const string &s: S){
        cout << s << endl;
    }
}


// int main(){
//     string X; cin >> X;
//     string alphabet = "abcdefghijklmnopqrstuvwxyz";
//     map<char, char> m;

//     for(int i=0; i<26; ++i){
//         m[X[i]] = alphabet[i]; 
//     }

//     int N; cin >> N;
//     vector<pair<string, string>> score_word(N);

//     for(int i=0; i<N; ++i){
//         string S; cin >> S;
//         string score = "";

//         for(char c:S){
//             score += m[c];
//         } 

//        score_word[i] = make_pair(score, S);
//     }
//     sort(score_word.begin(), score_word.end());

//     for(auto p : score_word){
//         cout << p.second << endl;
//     }

//     return 0;   
// }

// yqjowgdktlaheifmrcvnspxubz
// 5
// zzbpsqb
// zzagannw
// zzatqh
// zzzuy
// zzzz
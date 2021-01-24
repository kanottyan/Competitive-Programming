#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


bool solve(string s){
    //1keta
    if(s.size() == 1) return s == "8";

    //2keta
    if(s.size() == 2){
        if(stoi(s)%8 == 0) return true;
        swap(s[0], s[1]);
        if(stoi(s)%8 == 0) return true;
        return false;        
    }

    //3keta ijyou
    vector<int> cnt(10);
    for(int i=0; i<s.size(); ++i){
        int n = s[i] - '0';
        cnt[n]++;
    }

    for(int i=104; i<1000; i+=8){
        int x = i;
        vector<int> candidate(10);
        for(int j=0; j <3; ++j){
            candidate[x%10]++;
            x/=10;
        }
        bool ok = true;
        for(int k=0; k<10; ++k){
            if(cnt[k] - candidate[k] < 0) ok = false;
        }
        if(ok) return true;
    }
    return false;
}


int main(){
    string s;
    cin >> s;

    if(solve(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

// bool have_odd(){
//     bool res = false;
//     for(int i=1; i<10; i= i+2){
//         if( num[i] >0 ) res = true;
//     }
//     return res;
// }

// bool have_even(){
//     bool res = false;
//     for(int i=0; i<10; i= i+2){
//         if( num[i] > 0 ) res = true;
//     }
//     return res;
// }

// void remove_num(int i){
//     num[i]--;
// }

// int main(){

//     string s;
//     cin >> s;

//     // if(s.size() < 5){
//     //     string ans = "No";
//     //     int num = stoi(s);
//     //     if(num % 8 == 0) ans = "Yes";
//     //     cout << ans << endl;
//     //     return 0;
//     // }

//     if( s == "8" || s == "16" || s == "24" || s == "32" || s == "40" || s == "48"
//         || s == "56" || s == "64" || s =="72" || s=="80" || s == "88" || s == "96"
//         || s == "61" || s == "42" || s == "23" || s == "04" || s == "84" || s == "65"
//         || s == "46" || s == "27" || s == "08" || s == "69" || s == "104" || s == "140"
//         || s == "410" || s == "401" || s == "014" || s == "041"){
//             cout << "Yes" << endl;
//             return 0;
//         }

//     for(int i=0; i<s.size(); ++i){
//         int n = s[i] - '0';
//         num[n]++;
//     };

//     string ans = "No";
//     //１の桁0の場合
//     if(num[0] > 0){
//         num[0]--;
//         // 10のけたがなら
//         if(num[2] > 0){
//             num[2]--;
//             if( have_odd() ) ans = "Yes";
//             num[2]++;
//         }

//         if(num[6] > 0){
//             num[6]--;
//             if( have_odd() ) ans = "Yes";
//             num[6]++;
//         }

//         if(num[9] > 0){
//             num[9]--;
//             if( have_odd() ) ans = "Yes";
//             num[9]++;
//         }
//         //10のけたが0, 4, 8なら
//         if(num[0] >0){
//             num[0]--;
//             if( have_even() ) ans = "Yes";
//             num[0]++;
//         }

//         if(num[4] >0){
//             num[4]--;
//             if( have_even() ) ans = "Yes";
//             num[4]++;
//         }

//         if(num[8] >0){
//             num[8]--;
//             if( have_even() ) ans = "Yes";
//             num[8]++;
//         }
//         num[0]++;
//     }


//     //１の桁2の場合
//     if(num[2] > 0){
//         num[2]--;
//         // 10のけたが1,5,9なら
//         if(num[1] > 0){
//             num[1]--;
//             if( have_odd() ) ans = "Yes";
//             num[1]++;
//         }


//         if(num[5] > 0){
//             num[5]--;
//             if( have_odd() ) ans = "Yes";
//             num[5]++;
//         }

//         if(num[9] > 0){
//             num[9]--;
//             if( have_odd() ) ans = "Yes";
//             num[9]++;
//         }
//         //10のけたが3, 7なら
//         if(num[3] >0){
//             num[3]--;
//             if( have_even() ) ans = "Yes";
//             num[3]++;
//         }

//         if(num[7] >0){
//             num[7]--;
//             if( have_even() ) ans = "Yes";
//             num[7]++;
//         }
//         num[2]++;
//     }

//     //1のけた４の場合
//     if(num[4] > 0){
//         num[4]--;
//         // 10のけたが0, 4, 8なら
//         if(num[0] > 0){
//             num[0]--;
//             if( have_odd() ) ans = "Yes";
//             num[0]++;
//         }

//         if(num[4] > 0){
//             num[4]--;
//             if( have_odd() ) ans = "Yes";
//             num[4]++;
//         }

//         if(num[8] > 0){
//             num[8]--;
//             if( have_odd() ) ans = "Yes";
//             num[8]++;
//         }

//         //10のけたが2, 6なら
//         if(num[2] >0){
//             num[2]--;
//             if( have_even() ) ans = "Yes";
//             num[2]++;
//         }

//         if(num[6]>0){
//             num[6]--;
//             if( have_even() ) ans = "Yes";
//             num[6]++;
//         }
//         num[4]++;
//     }

//     //1のけた６の場合
//     if(num[6] > 0){
//         num[6]--;
//         // 10のけたが3, 7なら
//         if(num[3] > 0){
//             num[3]--;
//             if( have_odd() ) ans = "Yes";
//             num[3]++;
//         }


//         if(num[7] > 0){
//             num[7]--;
//             if( have_odd() ) ans = "Yes";
//             num[7]++;
//         }

//         //10のけたが1,5, 9なら
//         if(num[1] >0){
//             num[1]--;
//             if( have_even() ) ans = "Yes";
//             num[1]++;
//         }

//         if(num[5]>0){
//             num[5]--;
//             if( have_even() ) ans = "Yes";
//             num[5]++;
//         }

//         if(num[9]>0){
//             num[9]--;
//             if( have_even() ) ans = "Yes";
//             num[9]++;
//         }

//         num[6]++;
//     }

//     //1のけた8の場合
//     if(num[8] > 0){
//         num[8]--;
//         // 10のけたが2, 6なら
//         if(num[2] > 0){
//             num[2]--;
//             if( have_odd() ) ans = "Yes";
//             num[2]++;
//         }


//         if(num[6] > 0){
//             num[6]--;
//             if( have_odd() ) ans = "Yes";
//             num[6]++;
//         }

//         //10のけたが4, 8なら
//         if(num[0] >0){
//             num[0]--;
//             if( have_even() ) ans = "Yes";
//             num[0]++;
//         }

//         if(num[4] >0){
//             num[4]--;
//             if( have_even() ) ans = "Yes";
//             num[4]++;
//         }

//         if(num[8]>0){
//             num[8]--;
//             if( have_even() ) ans = "Yes";
//             num[8]++;
//         }
//         num[8]++;
//     }

//     cout << ans << endl;
//     return 0;
// }
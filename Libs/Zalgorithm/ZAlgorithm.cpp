#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Zalgo(string str){
    int n = str.size();
    int i=1, same=0;
    vector<int> z(n, 0);
    z[0] = n;

    while(i < n){
        while(i + same < n && str[same] == str[i+same]) same++;
        z[i] = same;

        if(same == 0){
            i++;
            continue;
        }

        int k = 1;
        while(k < same && k + z[k] < same){
            z[i+k] = z[k];
            k++;
        }
        i += k;
        same -= k;
    }
    return z;
}

// vector<int> Zalgo(string str){
//     int n = str.size();
//     vector<int> a(n, 0);
//     //もっとも後ろまで探索したやつを記憶
//     int from = -1; 
//     int last = -1;
//     a[0] = n;

//     for(int i=1; i<n; ++i){
//         int &same = a[i];
//         if(from != -1){
//             // 探索を短い方に揃える
//             same = min(a[i-from], last - i);
//             same = max(0, same);
//         }

//         while(i + same < str.size() && str[same] == str[i + same]) same++;
//         if(last < i + same){
//             last = i + same;
//             from = i;
//         }
//     }

//     return a;
// }


int main(){
    string str;
    cin >> str;

    auto a = Zalgo(str);
    for(auto elem: a) cout << elem << " "; cout << endl;
    return 0;
}
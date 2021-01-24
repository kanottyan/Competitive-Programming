#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
char apla[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
    long long N ;
    cin >> N;

    string ans;
    while(N >=1){
        long long a = N%26;
        N /=26;

        if(a >0){
            ans += apla[a-1];
        }else{
            ans += 'z';
            N -= 1;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

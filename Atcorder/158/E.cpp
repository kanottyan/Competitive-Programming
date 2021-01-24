#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    long long N, P; cin >> N >> P;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    long long len = s.size();

    long long ans =0;

    if( P == 2 || P == 5){
        for(long long i=0; i<len; ++i){
            long long digit = (s[i] - '0');
            if(digit % P == 0){
                ans += len - i;
            }
        }
    }else{
        vector<long long> d(len+1);
        long long keta = 1;
        d[0] = 0;
        vector<long long> count(P+1, 0);
        count[0]++;

        for(long long i=0; i<len; ++i){
            long long digit = (s[i] - '0');
            long long a = (digit * keta) %P;
            d[i+1] = (d[i] + a) % P;
            keta *= 10;
            keta %= P;
            count[d[i+1]]++;
        }

        for(long long i=0; i<P; ++i){
            if(count[i] > 1){
                    ans += (count[i] * (count[i]-1) )/2;
            }
        }
    }

    cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){
    int N; cin >> N;
    long long cnt = 0;

    set<int> s;
    long long counter = 0;

    if(N %7 == 0){
        N /= 7;
    }

    int keta = 1;
    while(true){
        keta %= N;
        cnt++;
        if(s.count(keta) > 0){
            cnt = -1;
            break;
        }else{
            s.insert(keta);
        }

        if(keta == 0) break;

        keta = keta* 10+1;
        keta %= N;
    }

    cout << cnt << endl;
}

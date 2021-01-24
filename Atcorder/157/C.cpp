#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int N, M; cin >> N >> M;
    vector<int> keta (N);
    for(int i=0; i<N; ++i){
        keta[i] = -1;
    }

    int ans = 0;
    for(int i=0; i<M; ++i){
        int s, c; cin >> s >> c;
        s--;
        if(N > 1 && s == 0 && c == 0){
            ans = -1;
            break;
        }

        if(keta[s] == -1){
            keta[s] = c;
        }else{
            if(keta[s] == c){
                continue;
            }else{
                ans = -1;
                break;
            }
        }
    }

    for(int i=0; i<N; ++i){
        if(keta[i] == -1){
            if(i == 0 && N > 1){
                keta[i] = 1;
            }else{
                keta[i] = 0;
            }
        }
    }

    if(ans != -1){
        for(int i=0; i<N; ++i){
            cout << keta[i];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}

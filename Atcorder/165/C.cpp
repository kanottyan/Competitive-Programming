#include <iostream>
#include <vector>
#include <functional>
#include <cstring>

using namespace std;

int main(){
    int N, M, Q;
    int a[55], b[55], c[55], d[55];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));

    cin >> N >> M >> Q;
    for(int i=0; i<Q; ++i){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
        a[i]--;
        b[i]--;
    }

    vector<int> A;
    for(int i=0; i<M-1; ++i) A.push_back(0);
    for(int i=0; i<N; ++i) A.push_back(1);


    int point = 0;
    do{
        int cnt =1;
        vector<int> retu;
        
        // convert A into the retu
        for(int i=0; i<A.size(); ++i){
            if(A[i] == 1){
                if(cnt == 0) cnt++;
                retu.push_back(cnt);
            }else{
                cnt++;
            }
        }
        
        int tmp_point =0;
        //apply the pint of the retu
        for(int i=0; i<Q; ++i){
            if(retu[b[i]] - retu[a[i]] == c[i]){
                tmp_point += d[i];
            } 
        }

        point = max(point, tmp_point);

    }while(next_permutation(A.begin(), A.end()));

    cout << point << endl;

}
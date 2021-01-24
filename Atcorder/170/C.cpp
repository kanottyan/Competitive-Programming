#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cant_use[101] = {false};

int main(){
    int X, N;
    cin >> X >> N;
    vector<int> p;


    for(int i=0; i<N; ++i){
        int a;
        cin >> a;
        p.push_back(a);
    }

    int ans;
    if( count(p.begin(), p.end(), X) == 0 ){
        ans = X;
    }else{
        //left
        int l = X-1;
        while( count(p.begin(), p.end(), l) > 0 ){
            --l;
        }

        //right 
        int r = X+1;
        while( count(p.begin(), p.end(), r) > 0 ){
            ++r;
        }

        if( abs(X-l) <= abs(r-X) ){
            ans = l;
        }else{
            ans = r;
        }

    }
    cout << ans << endl;



    for(int i=0; i<N; ++i){
        int a;
        cin >> a;
        cant_use[a] = true;
    }

    // //left
    // int tmp = X;
    // int left_idx = -1;
    // int left_dist;
    // while(tmp >= 0){
    //     if(cant_use[tmp] == true){
    //         tmp--;
    //     }else{
    //         left_idx = tmp;
    //         left_dist = abs(X- left_idx);
    //         break;
    //     }

    // }

    // //right
    // int tmp2 = X;
    // int right_idx = -1;
    // int right_dist;
    // while(tmp2 <= 100){
    //     if(cant_use[tmp2] == true){
    //         tmp2++;
    //     }else{
    //         right_idx = tmp2;
    //         right_dist = abs(tmp2 - X);
    //         break;
    //     }
    // }


    // //ans
    // int ans;
    // if(left_idx == -1){
    //     ans = right_idx;
    // }else if(right_idx == -1){
    //     ans = left_idx;
    // }else{
    //     if(left_dist <= right_dist){
    //         ans = left_idx;
    //     }else{
    //         ans = right_idx;
    //     }
    // }


    // cout << ans << endl;
}
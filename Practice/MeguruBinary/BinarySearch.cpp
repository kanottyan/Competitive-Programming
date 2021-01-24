//https://qiita.com/drken/items/97e37dd6143e33a64c8c

/*normal binary search*/
int a[] = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// 目的の値 key の index を返すようにする (ない場合は -1)
// int binary_search(int key){
//     int left = 0; 
//     int right = sizeof(a)/sizeof(a[0])-1; //// 配列 a の左端と右端
//     while(right >= left){
//         int mid = left + (right - left)/2; // 区間の真ん中
//         if( a[mid] == key)return mid;
//         else if(a[mid] > key) right = mid -1;
//         else if(a[mid] < key) left = mid +1;
//     }
//     return -1;
// }

#include <iostream>
#include <vector>

using namespace std;

bool isOK(int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int binary_search(int key){
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = sizeof(a)/sizeof(a[0]); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(abs(ok - ng) > 1){
        int mid = (ok + ng)/2;
        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return ok;
}

int main() {
    cout << binary_search(51) << endl; //  // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10(場外)
}
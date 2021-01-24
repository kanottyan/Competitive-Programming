#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    cout << "before: ";
    for(int i=0; i<n; ++i) cout << a[i] << "";
    cout << endl;

    /*intert sort from here */
    for(int i=1; i<n; ++i){
        int v = a[i];

        int j = i;
        for(; j>0; --j){
            // // v より大きいやつは 1 個後ろに移す
            if(a[j-1] > v){
                a[j] = a[j-1];
            }
            else break; // v 以下になったら止める
        }

        a[j] = v; // 最後に j 番目に v を挿入

        /* 各ステップの配列を出力してみる */
        cout << "After Step " << i << ": ";
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
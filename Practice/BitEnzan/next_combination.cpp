//n個の要素の集合 {0,1,…,n−1} の部分集合のうち、要素数が Kのもののみを列挙する方法を考えます。
#include <iostream>
#include <vector>

using namespace std;

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    int n = 5; // {0,1,2,3,4} no bubun syuugou
    int k =3;

    int bit = (1<<k)-1; // bit = {0, 1, 2}

    for(;bit < (1<<n); bit = next_combination(bit)){
        /* きちんとできていることを確認してみる */
        // bit の表す集合を求める
        vector<int> S;
        for(int i=0; i<n; ++i){
            if(bit & (1 << i)){
                S.push_back(i);
            }
        }
        // bit の表す集合の出力
        cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;
    }
}
#include<iostream>
#include<vector>

using namespace std;

// int 型を「どのアイテムを選ぶのか」を表す vector<int> 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N){
    vector<int> S;

    for(int i=0; i < N; ++i){
        if(bit & (1 <<i)){
            S.push_back(i);
        }
    }
    return S;
}

// 5 9
// 1 2 3 4 5

int main(){
    int N, W;
    cin >> N >> W;
    int a[N];
    for(int i=0; i<N; ++i) cin >> a[i];

    bool exist = false;
    for(int bit=0; bit< (1<<N); ++bit){
        // sum of bit
        int sum = 0;

        //to use which ? 
        //vector<int> S = IntegerToVector(bit, N);
        // for(int i : S) sum += a[i];

        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) sum += a[i];
        }

        // hatei
        if(sum == W) exist = true;
    }
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
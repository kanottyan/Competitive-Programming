#include<iostream>
#include<vector>

using namespace std;

int N;
vector< vector< pair<int, int> > >  v;

// int 型を「どのアイテムを選ぶのか」を表す vector<int> 型に変換
// bit: 集合を表す整数
bool judge(int bit){
    for(int i=0; i<N ; ++i){
        // i ga not kind , then no meaning to do the judge.
        if(!(bit & 1 << i)) continue;

        //if i is kind, then check the status
        for(pair<int, int> p: v[i]){
            int x = p.first;
            int y = p.second;
            // if y =1 but i is not kind
            if(y==1 && !(bit & 1<<x)) return false;
            // if y =0 but i is kind
            if(y==0 && (bit & 1<<x)) return false;
        }
    }

    return true;
}


int main(){
    cin >> N;
    v.resize(N);

    //init
    for(int i=0; i<N; ++i){
        int A;
        cin >> A;
        v[i].resize(A);

        for(int j=0; j < A; ++j){
            cin >> v[i][j].first;
            cin >> v[i][j].second;
            --v[i][j].first;
        }
    }

    int mx = 0;
    for(int bit=0; bit<(1<<N); ++bit){
        if(judge(bit)){
            int num_kind = __builtin_popcount(bit);
            mx = max(mx, num_kind);
        }
    }


    cout << mx << endl;
}
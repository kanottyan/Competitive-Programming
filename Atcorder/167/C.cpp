#include <iostream>
#include <vector>

using namespace std;

int book[12][13];

int main(){
    int N, M, X;
    cin >> N >> M >> X;

    for(int i=0; i<N; ++i){
        for(int j=0; j<=M; ++j){
            cin >> book[i][j];
        }
    }


    bool exist = false;
    int price = 100100100;
    for(int bit=0; bit < (1<<N); ++ bit){
        int tmp_price = 0;
        vector<int> status(M) ;

        for(int i=0; i<N; ++i){
            if(bit & (1<<i)){
                tmp_price += book[i][0];
                for(int j=0; j<M; ++j){
                    status[j] += book[i][j+1];
                }
            }
        }

        //hantei
        bool flag = true;
        for(int k=0; k<M; ++k){
            if( status[k] < X){
                flag = false;
            }
        }
        if(flag){
            exist = true;
            price = min(price, tmp_price);

        }
    }

    if(exist){
        cout << price << endl;
    }else{
        cout << -1 << endl;
    }
}
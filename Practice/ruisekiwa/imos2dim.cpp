// あなたは様々な種類のモンスターを捕まえるゲームをしています．
// 今あなたがいるのは W×H のタイルからなる草むらです．
// この草むらでは N 種類のモンスターが現れます．
// モンスター i は Ai≦x<Bi, Ci≦y<Di の範囲にしか現れません．
// このゲームを効率的に進めるため，1 つのタイル上で現れるモンスターの種類の最大値が知りたいです．
// （ただし，W×H は計算可能な程度の大きさとし，N は大きくなりうるものとします．）

//https://imoz.jp/algorithms/imos_method.html

//例
// 3
// 1 4 1 4
// 2 3 4 5
// 3 6 3 6

//ナイーブな方法

// #include <vector>
// #include <iostream>

// using namespace std;

// const int X = 10;
// const int Y = 10;
// int table[Y][X];

// int main(){
//     int N;
//     cin >> N;

//     // init
//     for(int y=0; y<Y; ++y){
//         for(int x=0; x<X; ++x){
//             table[y][x] = 0;
//         }
//     }

//     // モンスター i が現れる [(A[i],C[i]), (B[i],D[i])) の範囲に 1 を足す
//     for(int i=0; i<N; ++i){
//         int A, B, C, D;
//         cin >> A >> B >> C >> D;
//         --A; --B; --C; --D;
//         for(int y=C; y<=D; ++y){
//             for(int x=A; x<=B; ++x){
//                 table[y][x]++;
//             }
//         }
//     }

//     //最大値
//     int tile_max = 0;
//     for(int y=0; y<Y; ++y){
//         for(int x=0; x<X; ++x){
//             if(tile_max < table[y][x]){
//                 tile_max = table[y][x];
//             }
//         }
//     }

//     cout << tile_max << endl;
// }

//二次元imos法
// 矩形の左上 (A[i],C[i]) に +1 を，
// 右上 (A[i],D[i]) に −1 を，
// 左下 (B[i],C[i]) に −1 を，
// 右下 (B[i],D[i]) に +1 を加算し，
// 答えを求める直前に累積和を求めます．

#include <vector>
#include <iostream>

using namespace std;

const int X = 10;
const int Y = 10;
int table[Y][X];

int main(){
    int N;
    cin >> N;

    // init
    for(int y=0; y<Y; ++y){
        for(int x=0; x<X; ++x){
            table[y][x] = 0;
        }
    }

    // モンスターi が現れる [(A[i],C[i]), (B[i],D[i])) の範囲に 1 を足す
    for(int i=0; i<N; ++i){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        --A; --B; --C; --D;
        table[C][A]++;
        table[C][B+1]--;
        table[D+1][A]--;
        table[D+1][B+1]++;
    }

    //横方法に累積和
    for(int y=0; y<Y; ++y){
        for(int x=1; x<X; ++x){
            table[y][x] += table[y][x-1];
        }
    }

    //縦方法に累積和
    for(int x=0; x<X; ++x){
        for(int y=1; y<Y; ++y){
            table[y][x] += table[y-1][x];
        }
    }

    //最大値
    int tile_max = 0;
    for(int y=0; y<Y; ++y){
        for(int x=0; x<X; ++x){
            if(tile_max < table[y][x]){
                tile_max = table[y][x];
            }
        }
    }

    cout << tile_max << endl;
}

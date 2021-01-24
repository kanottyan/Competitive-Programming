#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const long long INF = 1LL << 60;


const int K = 43;
//dp[何桁目(0-42くらい)][繰り上がりあるか(0 or 1)][今までの範囲がA以下かどうか(0が以下or1がより大きい)] = 最大値
long long dp[K][2][2];

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    long long X =0;
    for(int i=2; i<N; ++i){
        X ^= A[i];
    }
    //１つ目をa２つ目をｂ，全体をSにする
    long long a = A[0];
    long long b = A[1];
    long long S = a + b;


    //init,その状態にイケナイに初期化
    for(int i=0; i<K; ++i){
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                dp[i][j][k] = -1;
            }
        }
    }
    //最初は0桁、繰り上がりなし、今の所A以下
    dp[0][0][0] = 0;
    //
    long long v = 1;

    for(int i=0; i<K-1; ++i){
        //今の桁をわかりやすく表現
        int cx = X&1;
        int cs = S&1;
        int ca = a&1;

        //4通りの状態
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                //遷移を考える(na, nbはA’とB')
                for(int na = 0; na<2; ++na){
                    for(int nb=0; nb <2; ++nb){
                        //今がもし行けない場所だったら何もできない
                        if( dp[i][j][k] == -1 ) continue;
                        //桁1つ増やす
                        int ni = i+1;
                        
                        int nj = 0;
                        
                        int nk = k;
                        
                        //今のくらいと一致してなかったらだめ
                        if((na^nb) != cx) continue;
                        //jは繰り上がり分
                        int ns = na + nb +j;
                        //sは普遍なので一致してないとだめ
                        if(ns % 2 != cs) continue;

                        //ここまでを満たせば遷移できる
                        //和が２以上なら繰り上がりが起きる
                        if(ns >= 2) nj = 1;
                        
                        // nkはaの桁とa'のけたを比較して
                        if(ca < na) {
                            //大きくなるなら１
                            nk = 1;
                        }else if (ca == na){
                            //一致ならkが変わらない
                            nk = k;
                        }else{
                            //小さいなら0
                            nk = 0;
                        }
                        //末尾にnaを追加したもの,vは桁が増えるごとに位置増える
                        dp[ni][nj][nk] = max(dp[ni][nj][nk], dp[i][j][k]|(v*na));

                    }
                }
            }
        }
        X >>= 1;
        S >>= 1;
        a >>= 1;
        v <<= 1;

    }

    //答え
    a = dp[K-1][0][0];
    if( a == -1 || a == 0){
        cout << -1 << endl;
        return 0;
    }

    long long ans = A[0] - a;
    cout << ans << endl;
    return 0;

    // //O(N)　解法
    // bool skip = false;
    // if(A[0] == 1) skip = true;

    // if(!skip){
    //     for(long long i=0; i<=A[0]; ++i){
    //         long long tmp = h ^ (A[0] -i) ^ (A[1] +i);
    //         if(tmp == 0){
    //             ans = i;
    //             break;
    //         }
    //     }        
    // }

    // cout << ans << endl;
}
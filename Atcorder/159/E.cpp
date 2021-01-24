#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<bool> > graph;

const int INF = 1LL << 30;


int main(){
    int H, W, K;
    cin >> H >> W >> K;

    graph.assign(H, vector<bool>());


    for(int h=0; h<H; ++h){
        string s;
        cin >> s;
        for(int w=0; w<W; ++w){
            int flag = s[w] - '0';
            graph[h].push_back(flag);
        }
    }

    //答え
    int ans = INF;

    //横の切り方はbit全探索2^H通り
    for(int bit=0; bit< (1 << (H-1)); ++bit){
        int group = 0;
        vector<int> id(H);
        //どのグループに属するかを決める
        for(int h=0; h<H; ++h){
            id[h] = group;
            if(bit >> h & 1){
                group++;
            }
        }
        group++;

        //各グループに今何個入っているか
        vector<vector<int>> group_nums(group, vector<int>(W));
        for(int h=0; h<H; ++h){
            for(int w=0; w<W; ++w){
                int group = id[h];
                if(graph[h][w] == true){
                    group_nums[group][w]++;
                }
            }
        }

        //縦に何回切るかを貪欲に計算
        bool skip = false;
        vector<vector<int>> group_cumsum(group, vector<int>(W));
        //縦の累積を初期化
        for(int i=0; i<group; ++i){
            group_cumsum[i][0] = group_nums[i][0];
        }

        //もし事前にグループがそもそも閾値を超えてたらそのbitの横の切り方はできないので、
        //調べない。
        for(int i=0; i<group; ++i){
            for(int w=0; w<W; ++w){
                if(group_nums[i][w] > K){
                    skip = true;
                }
            }
        }


        if(!skip){
            int tate = 0;
            int w=1;
            //一個ずつ切るか見ていく
            for(w=0; w< W; ++w){
                bool is_cut = false;
                for(int i=0; i<group; ++i){
                    long long next_num = group_cumsum[i][w-1] + group_nums[i][w];
                    if(next_num > K){
                        is_cut = true;
                    }
                }

                if(is_cut == true){
                    //カットする
                    tate++;
                    //そうすると次の累積和はgraph[g][w]に初期化される.
                    for(int i=0; i<group; ++i){
                        group_cumsum[i][w] = group_nums[i][w];
                        
                    }                    
                }else{
                    //カットしない場合は累積和を増やす
                    for(int i=0; i<group; ++i){
                        group_cumsum[i][w] = group_cumsum[i][w-1] + group_nums[i][w];
                        
                    }
                }
            }
            //グループの分ける切り方はgroup-1,
            int cut_num = tate + (group-1);
            ans = min(ans, cut_num);
        }
    }

    cout << ans << endl;
}
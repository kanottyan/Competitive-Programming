#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, M;
    cin >> H >> W >> M;

    vector<int> h_num(H);
    vector<int> w_num(W);
    int max_h = 0;
    int max_w = 0;

    set<pair<int, int>> s;

    for(int i=0; i<M; ++i){
        int h, w;
        cin >> h >> w;
        h--; w--;
        h_num[h]++;
        max_h = max(max_h, h_num[h]);
        w_num[w]++;
        s.emplace(h, w);
        max_w = max(max_w, w_num[w]);
    }

    //candidate h, w, indexs
    vector<int> candidate_h_idx;
    for(int h=0; h<H; ++h){
        if(h_num[h] != max_h) continue;
        candidate_h_idx.push_back(h);
    }


    vector<int> candidate_w_idx;
    for(int w=0; w<W; ++w){
        if(w_num[w] != max_w) continue;
        candidate_w_idx.push_back(w);
    }

    //tmp ans
    int ans = max_h + max_w;

    //check if all the points are crossed or not
    bool all_crossed = true;

    for(int h : candidate_h_idx){
        for(int w : candidate_w_idx){
            if(s.count({h, w})) continue;
            all_crossed = false;
            break;
        }
    }

    if(all_crossed){
        cout << ans -1 << endl;
    }else{
        cout << ans << endl;
    }

}

// int h_num[300100];
// int w_num[300100];

// int main(){
//     int H, W, M;
//     cin >> H >> W >> M;

//     set<pair<int, int>> s;
//     for(int h=0; h<H; ++h){
//         h_num[h] = 0;
//     }

//     for(int w=0; w<W; ++w){
//         w_num[w] = 0;
//     }

//     for(int i=0; i<M; ++i){
//         int h, w;
//         cin >> h >> w;
//         h--; w--;

//         h_num[h]++;
//         w_num[w]++;
//         s.emplace(h, w);
//     }

//     int h_max = 0;
//     int h_index = -1;
//     int w_max = 0;
//     int w_index = -1;

//     set<int> w_idx_candidate;
//     set<int> h_idx_candidate;

//     for(int h=0; h<H; ++h){
//         if( h_max < h_num[h] ){
//             h_max = h_num[h];
//             h_index = h;
//             h_idx_candidate.clear();
//             h_idx_candidate.insert(h_index);
//         }else if(h_max == h_num[h]){
//             h_idx_candidate.insert(h);
//         }
//     }

//     for(int w=0; w<W; ++w){
//         if( w_max < w_num[w] ){
//             w_max = w_num[w];
//             w_index = w;
//             w_idx_candidate.clear();
//             w_idx_candidate.insert(w);
//         }else if(w_max == w_num[w]){
//             w_idx_candidate.insert(w);
//         }
//     }

//     bool flag = false;
//     if(h_max > w_max){
//         for(int w_idx: w_idx_candidate){
//             if(s.count({h_index, w_idx}) == 0){
//                 flag = true;
//             }
//         }
//     }else{
//         for(int h_idx: h_idx_candidate){
//             if(s.count({h_idx, w_index}) == 0){
//                 flag = true;
//             }
//         }
//     }


//     int ans = h_max + w_max;
//     if(flag == false){
//         ans -= 1;
//     }

//     cout << ans << endl;
// }
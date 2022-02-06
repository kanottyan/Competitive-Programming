#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

int N;
vector<vector<int>> A;
int ans = -1;

void dfs(vector<bool> used, int pair_num, int cur_n){
    if(pair_num == N){
        ans = max(ans, cur_n);
        return;
    }
    int next_candidate_first = -1;
    int next_candidate_second = -1;

    for(int i=0; i<N*2; ++i){
        if(used[i] == true) continue;
        next_candidate_first = i;
        used[next_candidate_first] = true;
        break;
    }

    for(int i=0; i<N*2; ++i){
        if(used[i] == true) continue;
        next_candidate_second = i;
        cur_n ^= A[next_candidate_first][next_candidate_second];
        used[next_candidate_second] = true;
        dfs(used, pair_num+1, cur_n);
        used[next_candidate_second] = false;
        cur_n ^= A[next_candidate_first][next_candidate_second];
    }
}

int main(){
    cin >> N;
    A.resize(N*2, vector<int>(N*2));
    vector<bool> used(N*2);
    
    for(int i=0; i<2*N; ++i){
        for(int j=0; j<2*N; ++j){
            if(i >= j) continue;
            int a; cin >> a;
            A[i][j] = a;
            A[j][i] = a;
        }
    }

    used[0] = true;
    for(int i=1; i<N*2; ++i){
        used[i] = true;
        dfs(used, 1, A[0][i]);
        used[i] = false;
    }
    cout << ans << endl;
}

// int main(){
//     int N; cin >> N;
//     vector<vector<int>> A(2*N, vector<int>(2*N, -1));

//     for(int i=0; i<2*N; ++i){
//         for(int j=0; j<2*N; ++j){
//             if(i >= j) continue;
//             int a; cin >> a;
//             A[i][j] = a;
//             A[j][i] = a;
//         }
//     }

//     vector<int> ppl(2*N);
//     for(int i=0; i<2*N; ++i){
//         ppl[i] = i;
//     }

//     int ans = 0;

//     do{
//         int tmp = 0;
//         for(int i=0; i<2*N; i += 2){
//             int a = ppl[i];
//             int b = ppl[i+1];
//             int s = A[a][b];
//             tmp ^= s;
//         }
//         ans = max(ans, tmp);

//     }while(next_permutation(ppl.begin(), ppl.end()));

//     cout << ans << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
vector<int> ans;
queue<int> q;

int main(){

    int N, M;
    cin >> N >> M;
    ans.assign(N, -1);
    G.resize(N);


    for(int i=0; i< M; ++i){
        int A, B;
        cin >> A >> B;
        --A; --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    q.push(0);
    ans[0] = 1;

    bool can_go = false;

    while(q.size() > 0){
        int cur_node = q.front();
        q.pop();
        for(auto next_node: G[cur_node]){
            if( ans[next_node] == -1 ){
                ans[next_node] = cur_node;
                q.push(next_node);
                can_go = true;
            }
        }
    }

    if(can_go){
        cout << "Yes" << endl;
        for(int i=1; i<N; ++i){
            if( ans[i] == -1 ){
                cout << "No" << endl;
            }else{
                cout << ans[i]+1 << endl;
            }
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}
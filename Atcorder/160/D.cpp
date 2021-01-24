#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > G;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;

    G.assign(N, vector<int>() );

    //init
    for(int i=0; i<N-1; ++i){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    vector<int> ans(N);

    for(int i=0; i<N; ++i){
        vector<int> visited;
        visited.assign(N, -1);
        queue<int> q;

        q.emplace(i);
        visited[i] = 0;

        while(!q.empty()){
            int cur_node = q.front();
            q.pop();

            for(auto nn : G[cur_node]){
                if(visited[nn] != -1) continue;
                visited[nn] = visited[cur_node] + 1;
                q.emplace(nn);
            }
        }

    for(int i=0; i< visited.size(); ++i){
            ans[visited[i]]++;
        }
    }

    for(int i=1; i<ans.size(); ++i){
        cout << ans[i]/2 << endl;
    }

    return 0;
} 
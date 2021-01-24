#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long N, M;
    cin >> N >> M;

    vector<bool> good_tenbou(N);
    vector<long long> height(N);
    vector<vector<int> > G(N);

    for(int i=0; i<N; ++i){
        good_tenbou[i] = 0;
    }
    
    for(int i=0; i<N; ++i){
        cin >> height[i];
    }

    for(int i=0; i<M; ++i){
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    for(int i=0; i<N; ++i){
        bool flag = true;
        if(G[i].size() >0){
            for( auto j: G[i]){
                if( i != j){
                    int test = height[i];
                    int test2 = height[j];
                    if( height[i] <= height[j] ){
                        flag = false;
                        break;
                    }
                }
            }
        }else{
            good_tenbou[i] = true;
        }

        if(flag){
            good_tenbou[i] = true;
        }
   
    }

    int ans=0;
    for(int i=0; i<N; ++i){
        if(good_tenbou[i] == true){
            ans++;
        }
    }

    cout << ans << endl;
}
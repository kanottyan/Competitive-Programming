#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for(int i=0; i<N; ++i) v[i] = 0;

    for(int i=0; i<K; ++i){
        int okasi;
        cin >> okasi;
        for(int j=0; j<okasi; ++j){
            int who;
            cin >> who;
            who--;
            v[who]++;
        }
    }

    int count = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i]  ==0){
            count++;
        }
    }

    cout << count << endl;
}
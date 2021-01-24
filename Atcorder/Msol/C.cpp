#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


int main(){
    int n; cin >> n;
    int k; cin >> k;

    vector<long long> score(n);
    for(int i=0; i<n; ++i){
        cin >> score[i];
    }

    long long cumsum = 0;
    for(int i=0; i<k; ++i){
        cumsum += score[i];
    }

    long long current_score = cumsum;
    for(int i=k; i<n; ++i){
        cumsum -= score[i - k];
        cumsum += score[i];

        if(current_score < cumsum){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        current_score = cumsum;
    }
}
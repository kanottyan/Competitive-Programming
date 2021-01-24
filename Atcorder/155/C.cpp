#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main(){
    int N;
    cin >> N;

    map<string, int> dict;
    int maxcounter = 0;

    for(int i=0; i<N; ++i){
        string s;
        cin >> s;

        if(dict.count(s) > 0){
            dict[s] += 1;
        }else{
            dict[s] = 1;
        }
        maxcounter = max(maxcounter, dict[s]);
    }

    for(auto word_counter: dict){
        if(word_counter.second == maxcounter){
            cout << word_counter.first << endl;
        }
    }

}
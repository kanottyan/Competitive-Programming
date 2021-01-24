#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
    string s;
    cin >> s;

    deque<char> deq;
    for(int i=0; i<s.size(); ++i){
        deq.push_back(s[i]);
    }

    int Q; cin >> Q;
    int one_counter = 0;

    for(int i=0; i<Q; ++i){
        int q; cin >> q;
        if(q == 1){
            one_counter++;
        }else{
            int f; cin >> f;
            char c; cin >> c;

            if( one_counter %2 == 0 ){
                if(f == 1){
                    deq.push_front(c);
                }else{
                    deq.push_back(c);
                }
            }else{
                if(f == 1){
                    deq.push_back(c);
                }else{
                    deq.push_front(c);
                }
            }
        }
    }
    if(one_counter % 2 == 1){
        reverse(deq.begin(), deq.end());
    }

    while(!deq.empty()){
        char c = deq.front();
        deq.pop_front();

        cout << c;
    }
    cout << endl;

}
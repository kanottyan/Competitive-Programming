#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> s(N);
    for(int i=0; i<N; ++i) cin >> s[i];

    set<string> st;

    for(int i=0; i<N; ++i){
            st.insert(s[i]);
    }

    cout << st.size() << endl;
}
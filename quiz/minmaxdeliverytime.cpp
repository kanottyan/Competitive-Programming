#include <bits/stdc++.h>
// Tou have 3 planned delivery from Monday - Friday.
// calc the extimated waitimg time.
// waiting time here = the last delivery date - first delivery 
// each delivery is indentical and will be send in 1/5 probability in a day

using namespace std;

int min_freq[5];
int max_freq[5];

int main(){

    for(int i=1; i<=5; ++i)for(int j=1; j<=5; ++j)for(int k=1; k<=5; ++k){
        int mi = min({i, j, k});
        int mx = max({i, j, k});
        
        min_freq[mi-1]++;
        max_freq[mx-1]++;
    }
    cout << "Min Freq" << endl;
    copy(min_freq, min_freq+5, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Max Freq" << endl;
    copy(max_freq, max_freq+5, ostream_iterator<int>(cout, " "));
    cout << endl;

    int ans = 0;
    for(int i=1; i<=5; ++i){
        ans += i*(max_freq[i-1]- min_freq[i-1]);
    }

    cout << "Ans: " << ans << "/125" << endl;

}
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


int main(void) {
    int n,d;
    std::cin >> n >> d;
    
    std::vector<int> days(n);
    for (auto& e : days)
        std::cin >> e;
    
    std::vector<size_t> freq(201);
    size_t i = 0;
    for (; i < d; ++i)
        ++freq[days[i]];
    for (size_t j = 1; j < freq.size(); ++j)
        freq[j] += freq[j-1];

    size_t cnt = 0;
    double tmp;
    
    size_t j;
    while(i < n) {
        for (j = 0; j < freq.size() && freq[j] < d/2; ++j);
        
        //  freq[j] >= d/2
        if (freq[j] == d/2) {
            tmp = j+1;
            if (d % 2 == 0) {
                tmp += j;
                tmp /= 2;
            }
        } else {
            tmp = j;
            if (d % 2 == 0) {
                tmp += freq[j-1] + 1 == freq[j] ? j-1 : j;
                tmp /= 2;
            }
        }
        tmp *= 2;
        
        cnt += days[i] >= tmp;

        for (j = days[i-d]; j < freq.size(); ++j)
            --freq[j];
        for (j = days[i]; j < freq.size(); ++j)
            ++freq[j];
        
        ++i;
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}

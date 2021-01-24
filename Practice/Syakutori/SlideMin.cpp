//スライド最小値問題　
//https://qiita.com/kuuso1/items/318d42cd089a49eeb332

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using pll = pair<long, long, long long>;

// slide min

template<class VAL, class TIME> struct SlideMin{
    const VAL INF = 1LL<<60; // to be set appropriately
    const TIME nul = -1; // to be set appropriately

    deque<pair<VAL, TIME> > deq;
    SlideMin() {}

    //get minimum
    pair<VAL, TIME> get() {
        if (deq.empty()) return make_pair(INF, nul);
        return deq.front();
    }

    // push(v, t), "t is non-decreasing" is necesarry
    void push(VAL v, TIME t){
        while(!deq.empty() && deq.back().first >= v) deq.pop_back();
        deq.emplace_back(v, t);
    }

    // pop "<t", "t is non-decreasing" is necesarry
    void pop(TIME t){
        while(!deq.empty() && deq.front.second <t) deq.pop_front();
    }


}
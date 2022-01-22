#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;


class Customer{
    private:
        map<int, int> m;

    public:
    void add(int a, int b){
        m[a] = b;
    }

    map<int,int>* get(){
        return &m;
    }

    void update(int i, int val){
        m[i] = val;
    }
};

int main(){

    Customer c;
    c.add(1,2);
    c.add(3,3);
    c.add(4,5);

    map<int, int>* res = c.get();
    c.update(5, 100);

    res->insert(make_pair(11, 111));
    res->insert(make_pair(13, 111));

    return false;
}
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

    // Customer c;
    // c.add(1,2);
    // c.add(3,3);
    // c.add(4,5);

    // map<int, int>* res = c.get();
    // c.update(5, 100);

    // res->insert(make_pair(11, 111));
    // res->insert(make_pair(13, 111));

    int cnt = 0;
    int N=7;
    for(int bit=0; bit<(1<<N); ++bit){
        int c = 0;
        for(int i=0; i<N; ++i){
            if(bit & (1<<i)){
                c++;
            }else{
                c = 0;
            }
            if(c == 3){
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;

    return false;
}
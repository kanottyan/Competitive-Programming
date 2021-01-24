#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<long long> p(A);
    for(int i=0; i<A; ++i) cin >> p[i];
    vector<long long> q(B);
    for(int i=0; i<B; ++i) cin >> q[i];
    vector<long long> r(C);
    for(int i=0; i<C; ++i) cin >> r[i];

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    multiset<long long> s;

    for(int i=A-1; i>(A-1)-X; --i){
        s.insert(p[i]);
    }

    for(int i=B-1; i>(B-1)-Y; --i){
        s.insert(q[i]);
    }

    int num = min(A+B, C);
    for(int i=C-1; i>(C-1)-num; --i){
        long long smallest = *s.begin();
        if(r[i] > smallest){
            s.erase(s.find(smallest));
            s.insert(r[i]);
        }
    }

    long long sum = 0;
    for(long long i : s) sum += i;
    cout << sum << endl;
}
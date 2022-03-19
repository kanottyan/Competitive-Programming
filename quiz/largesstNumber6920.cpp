// you can use 6, 9, 20 any times to sum the total to make a new number.
// what is the largest number which can not make as the total number.
#include <bits/stdc++.h>

using namespace std;

const int MAX = __INT_MAX__;
vector<bool> memo(MAX);

bool rec(long long n){

    if(n < 0){
        return false;
    }

    if(n == 6 || n == 9 || n == 20){
        return true;
    }

    return memo[n] = rec(n-6) | rec(n-9) | rec(n-20);
}


int main(){
    int a = 6;
    int b = 9;
    int c= 20;

    // for(int i=0; i<100; ++i){
    //     cout << i << ": " << rec(i) << endl;
    // }

    set<int> nums;

    queue<int> q;
    q.push(6);
    q.push(9);
    q.push(20);

    for(int i=0; i<10000; ++i){
        int num = q.front();
        q.pop();
        nums.insert(num);

        q.push(num+a);
        q.push(num+b);
        q.push(num+c);
    }

    cout << "test" << endl;
}

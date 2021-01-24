#include <iostream>
#include <vector>

using namespace std;

long long num_counter[100100];
//int num_counter[101];

int main(){
    long long N;
    cin >> N;
    for(long long i=1; i<=N; ++i){
        long long j;
        cin >> j;
        num_counter[j]++;
    }

    long long ans = 0;
    for(long long i=1; i<=100100; ++i){
        long long tmp = (i * num_counter[i]);
        ans += tmp;
    }

    long long Q;
    cin >> Q;
    for(long long i=0; i<Q; ++i){
        long long B, C;
        cin >> B >> C;


        long long tmp = num_counter[B];
        num_counter[C] += tmp;
        num_counter[B] = 0;

        ans -= (B * tmp);
        ans += (C * tmp);

        cout << ans << endl;
    }

}
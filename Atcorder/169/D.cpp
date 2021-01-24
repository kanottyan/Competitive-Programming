#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N){
    vector<pair<long long, long long> > res;
    for(long long a = 2; a*a <= N; ++a){
        if(N % a != 0)continue;
        long long ex = 0; //指数

        // 割れる限り続ける
        while( N%a == 0){
            ++ex;
            N /= a;
        }

        res.push_back( {a, ex} );
    }

    // 最後に残った数について
    if(N != 1) res.push_back({N, 1});
    return res;
}

long long counter(long long N){
    long long counter = 0;
    long long num = 1;

    while(N > 0){
        if( num > N){
            break;
        }
        N -= num;
        num ++;
        counter++;
    }

    return counter;
}


int main(){
    long long N;
    cin >> N;

    long long ans = 0;
    const auto& res = prime_factorize(N);   
    for(auto p: res){
        ans = ans + counter(p.second);
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    long long div = N/K;

    long long K_dash;
    long long N_dash; 
    if(div >0){
        K_dash = div*K;
        N_dash = abs(N - K_dash);
    }else{
        N_dash = N;
    }

    while(true){
        long long tmp = abs(N_dash - K);
        if(tmp < N_dash){
            N_dash = tmp;
        }else{
            break;
        }
    }

    cout << N_dash << endl;
}
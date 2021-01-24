#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long  A, V;
    cin >> A >> V;
    long long B, W;
    cin >> B >> W;

    long long T;
    cin >> T;

    long long dist;
    if( B >=0 ){
        dist = B - A;
    }else{
        dist = abs(B - A);
    }

    long long speed = V - W;
    if( speed * T >= dist){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
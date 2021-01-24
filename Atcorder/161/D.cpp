#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

//別海
int main(){
    int K;
    cin >> K;
    vector<long long> a;

    for(int i=1; i<10; ++i){
        a.push_back(i);
    }

    while(true){
        if(K <= a.size()){
            cout << a[K-1] << endl;
            return 0;
        }
        K -= a.size();
        vector<long long> old;
        swap(old, a);

        for(long long x : old){
            for(int i= -1; i<=1; ++i){
                //末尾にくっつける末尾の数
                int d = x%10 + i;
                if(d <0 || d > 9)continue;
                long long nx = x*10 + d;
                a.push_back(nx);
            }
        }
    }
}

// int main(){
//     long long K;
//     cin >> K;
//     deque<long long> d;

//     //init 
//     for(int i=1; i<=9; ++i){
//         d.emplace_back(i);
//     }

//     long long cnt = 0;

//     while(true){
//         cnt++;
//         if(cnt == K) break;
//         long long f = d.front();
//         d.pop_front();
//         long long new_num = 10*f + (f%10);

//         if(new_num%10 != 0){
//             d.emplace_back(new_num - 1);
//         }
//         d.emplace_back(new_num );
//         if(new_num % 10 != 9){
//             d.emplace_back( new_num + 1 );
//         }

//     }

//     cout << d.front() << endl;
// }
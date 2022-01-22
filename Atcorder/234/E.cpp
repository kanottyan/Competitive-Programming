#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

vector<long long> candidates;

void generate_arithmetic_by_digit(int digit){
    //odd
    if(digit %2 == 1){
        int mid = digit/2;

        int d_count = (digit-1)/2;
        for(int d=0; d< 10; ++d){
            // go up
            for(int m=0; m<10; ++m){
                vector<int> res(digit);
                res[mid] = m;
                bool flag = true;
                for(int c=1; c<=d_count; ++c){
                    res[mid+c] = res[mid]+(d*c);
                    res[mid-c] = res[mid]-(d*c);
                    if( res[mid+c] > 9 || res[mid+c] < 0){
                        flag = false;
                        break;
                    } 
                    if( res[mid-c] > 9 || res[mid-c] < 0){
                        flag = false;
                        break;
                    } 
                }
                if(res[0] == 0) continue;
                if(flag == false) continue;
                //to long long;
                long long num = 0;
                long long keta = 1;
                for(int i=digit-1; i>=0; --i){
                    num += keta*res[i];
                    keta *= 10;
                }
                candidates.push_back(num);
            }


            for(int m=0; m<10; ++m){
                vector<int> res(digit);
                res[mid] = m;
                // go up
                bool flag = true;
                for(int c=1; c<=d_count; ++c){
                    res[mid+c] = res[mid]-(d*c);
                    res[mid-c] = res[mid]+(d*c);
                    if( res[mid+c] > 9 || res[mid+c] < 0){
                        flag = false;
                        break;
                    } 
                    if( res[mid-c] > 9 || res[mid-c] < 0){
                        flag = false;
                        break;
                    } 
                }
                if(res[0] == 0) continue;
                if(flag == false) continue;
                //to long long;
                long long num = 0;
                long long keta = 1;
                for(int i=digit-1; i>=0; --i){
                    num += keta*res[i];
                    keta *= 10;
                }
                candidates.push_back(num);
            }
        }
    }else{
        int mid_up = digit/2;
        int mid_down = digit/2-1;
        int d_count = (digit-2)/2;
        for(int d=0; d< 10; ++d){
            // go up
            for(int m=0; m<10; ++m){
                vector<int> res(digit);
                res[mid_down] = m;
                bool flag = true;            
                if(d != 0){
                    res[mid_up] = res[mid_down] + d;
                    if( res[mid_up] > 9 || res[mid_up] < 0 ){
                        flag = false;
                        continue;
                    }
                }else{
                    res[mid_up] = res[mid_down];
                }

                for(int c=1; c<=d_count; ++c){
                    res[mid_up+c] = res[mid_up] +(d*c);
                    res[mid_down-c] = res[mid_down]-(d*c);
                    if( res[mid_up+c] > 9 || res[mid_up+c] < 0){
                        flag = false;
                        break;
                    } 
                    if( res[mid_down-c] > 9 || res[mid_down-c] < 0){
                        flag = false;
                        break;
                    } 
                }
                
                if(res[0] == 0) continue;
                if(flag == false) continue;
                //to long long;
                long long num = 0;
                long long keta = 1;
                for(int i=digit-1; i>=0; --i){
                    num += keta*res[i];
                    keta *= 10;
                }
                candidates.push_back(num);
            }

            //go down
            for(int m=0; m<10; ++m){
                vector<int> res(digit);
                res[mid_down] = m;

                bool flag = true;            
                if(d != 0){
                    res[mid_up] = res[mid_down] - d;
                    if( res[mid_up] > 9 || res[mid_up] < 0 ){
                        flag = false;
                        continue;
                    }
                }else{
                    res[mid_up] = res[mid_down];
                }


                for(int c=1; c<=d_count; ++c){
                    res[mid_up+c] = res[mid_up]-(d*c);
                    res[mid_down-c] = res[mid_down]+(d*c);
                    if( res[mid_up+c] > 9 || res[mid_up+c] < 0){
                        flag = false;
                        break;
                    } 
                    if( res[mid_down-c] > 9 || res[mid_down-c] < 0){
                        flag = false;
                        break;
                    } 
                }
                if(res[0] == 0) continue;
                if(flag == false) continue;
                //to long long;
                long long num = 0;
                long long keta = 1;
                for(int i=digit-1; i>=0; --i){
                    num += keta*res[i];
                    keta *= 10;
                }
                candidates.push_back(num);
            }
        }
    }
}



int main(){
    long long X; cin >> X;
    string sx = to_string(X);

    int s = sx.size();
    generate_arithmetic_by_digit(s);
    generate_arithmetic_by_digit(s+1);

    sort(candidates.begin(), candidates.end());


    auto itr = lower_bound(candidates.begin(), candidates.end(), X);
    cout << *itr << endl;



    return 0;
}
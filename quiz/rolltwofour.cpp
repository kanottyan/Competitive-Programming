#include <bits/stdc++.h>

using namespace std;

int main(){

    srand(time(NULL));
    int trial = 1000000;
    int conditonal_trial = trial;
    int sum = 0;

    for(int i=0; i<trial; ++i){
        int roll = 0;
        while(true){
            roll++;
            int n = rand() %6;
            if(n == 1 || n == 3 | n == 5 || n == 0){
                if(n != 0){
                    roll = 0;
                    conditonal_trial--;
                } 
                break;
            }
        }
        sum += roll;
    }

    cout << (double) sum / (double) conditonal_trial << endl;

}
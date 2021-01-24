#include <vector>
#include <iostream>

using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >>D;

    bool a_hp_flag = true;
    bool c_hp_flag = true; 

    while(a_hp_flag > 0 || c_hp_flag > 0){
        C = C - B;
        if(C <= 0){
            c_hp_flag = false;
            break;
        } 

        A =  A - D;
        if(A <= 0){
            a_hp_flag = false;
            break;
        } 
    } 

    if(a_hp_flag == false){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
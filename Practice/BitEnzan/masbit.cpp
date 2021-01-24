#include <iostream>
#include <bitset>
using namespace std;

const unsigned int BIT_FLAG_DAMAGE = (1 << 0); // HP が満タンでないか
const unsigned int BIT_FLAG_DOKU = (1 << 1); // 毒状態になっているか
const unsigned int BIT_FLAG_MAHI = (1 << 2); // 麻痺状態になっているか
const unsigned int BIT_FLAG_SENTOFUNO = (1 << 3); // 戦闘不能状態になっているか

const unsigned int MASK_ATTACK = BIT_FLAG_DAMAGE;
const unsigned int MASK_PUNCH = BIT_FLAG_DAMAGE | BIT_FLAG_MAHI;
const unsigned int MASK_DEFEAT = BIT_FLAG_DAMAGE | BIT_FLAG_SENTOFUNO;
const unsigned int MASK_DOKU_MAHI = BIT_FLAG_DOKU | BIT_FLAG_MAHI;

int main(){
    // start: 0000, init status
    unsigned int status = 0;
    cout << "start: " << bitset<4>(status) << endl;

    // attacked: status to be 0001
    status |= MASK_ATTACK;
    cout << "attached: " << bitset<4>(status) << endl;


    // attacked: status to be 0001
    status |= MASK_PUNCH;
    cout << "pubched: " << bitset<4>(status) << endl;

    if(status & MASK_DOKU_MAHI){
        cout << "you are doku or mahi." << endl;
    }

    //kaihuku
    status &= ~MASK_DOKU_MAHI;
    cout << "kaihuku: " << bitset<4>(status) << endl;

    //defeat: to be 1001;
    status |= MASK_DEFEAT;
    cout << "sentoufuno: " << bitset<4>(status) << endl;    

    //kaihuku: but can't recover sountou funo
    status &= ~MASK_DOKU_MAHI;
    cout << "sentofuno no mama: " << bitset<4>(status) << endl;
}
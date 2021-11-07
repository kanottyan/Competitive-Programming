// You are a gambler and a Cubs fan. THe Cubs are competing in a seven-game series against the Red sox. -first to four games wins. 
// Your bookie agrees to take any even-odds bets on any of the individual games. 
// Can you construct a series of bets such that the guaranteed outcomes are : 
// You win $100 if the Cubs wins the series and lose $100 if the Red Sox win it ? 

#include <bits/stdc++.h>
using namespace std;


map<int, set<string>> m;


void rec(string s){
    int c = count(s.begin(), s.end(), 'c');
    int r = count(s.begin(), s.end(), 'r');
    if(c == 4){
        m[0].insert(s);
        return;
    }     
    if(r == 4){
        m[1].insert(s);
        return;
    } 
    string choice = "cr";
    for(char c : choice){
        rec(s+c);
    }
}


int main(){
    rec("");

    double cumsum = 0;
    //double factor = 1;

    for(auto s: m[0]){
        int tmp = 0;
        double pay = 25;
        for(char c : s){
            if(c == 'c'){
                tmp += pay;
                pay = 25;
            }else{
                tmp -= pay;
                //factor++;
                pay *= 2;
            }
        }
        cumsum += tmp;
        cout << s << ": " << tmp << endl;
    }


    // for(auto s: m[1]){
    //     int tmp = 0;
    //     double pay = 25;
    //     for(char c : s){
    //         if(c == 'c'){
    //             tmp += pay;
    //             pay = 25;
    //         }else{
    //             tmp -= pay;
    //             //factor++;
    //             pay *= 2;
    //         }
    //     }
    //     cumsum += tmp;
    //     cout << s << ": " << tmp << endl;
    // }



    cout << cumsum << endl;
}

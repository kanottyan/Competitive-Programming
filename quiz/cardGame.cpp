// there are 52 cards. 26 is black. 26 red
// shulle them and select once card, if you draw black you lose 1 dollar.
// if you draw red you get 1 dollar. you don't retrun the drawn care to deck.
// what is the optimal stopping rule to mazimize the expected payoff ?
#include <bits/stdc++.h>

using namespace std;

int main(){
    int cards = 6;
    long long N = 1LL<<cards;
    vector<pair<int, double>> v;

    for(int s = 0; s<cards; ++s){
        //case: wining count, prob
        map<string, pair< int,double>> m;

        int stop_condition = s;

        for(long long bit=0; bit< N; ++bit){
            double win = 0;
            double lose = 0;

            for(long long i=0; i<cards; ++i){
                if((bit>>i)&1) win++; else lose++;
            }

            if(!(win == cards/2 && lose == cards/2)) continue;

            double prob = 1.0;
            int win_count = 0;
            string s = "";

            for(int i=0; i<cards; ++i){
                s += ((bit>>i)&1) + '0';
                if((bit>>i)&1){
                    win_count++;
                    prob *= win/(win + lose);
                    win--;
                }else{
                    win_count--;
                    prob *= lose/(win + lose);
                    lose--;
                }

                if(win_count > stop_condition){
                    break;
                }
            }

            if(m.count(s)){
                continue;
            }

            m[s] = {win_count, prob};

        }

        double exp = 0;

        for(auto p: m){
            exp += (double)p.second.first * p.second.second;
        }

        cout << "win : " << s+1 << "first time and stop, exp is" << setprecision(40) << fixed <<exp << endl;
    }
}
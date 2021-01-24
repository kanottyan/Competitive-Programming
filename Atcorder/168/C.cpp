#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double ans;

    //kakudo 
    double ang;
    ang = (30*H+ 0.5*M)-6*M;

    if(abs(ang) == 180){
        ans = A + B;
    }else if(ang == 0){
        ans = abs(A-B);
    }else{
        if( -360.0 < ang || ang <= (double)-180.0 ){
            ang += 360.0;
        }else if(-180.0 < ang || ang < 0.0 ){
            ang = abs(ang);
        }else if( 0.0 < ang || ang < 180.0){
            ang = abs(ang);
        }else{
            ang -= 180.0; 
        }


        double cosine = cos(ang * M_PI / 180.0);
        double tmp = (A*A)  + (B*B) - (2.0 * A * B * cosine);
        ans = sqrt(tmp);
    }


    cout << fixed << setprecision(10) << ans << endl;
}
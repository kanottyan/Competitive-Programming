#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;


// 繰り返し二乗法
long long continuous_pow(long long a, long long b){
	long long res=1;
	while(b>0){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

long long combination(long long n, long long r){
  long long x = 1;
  long long y = 1;
  for(int i = n-r+1; i < n+1; i++){
    x = x*i%MOD;
  }

  for(int i = 1; i < r+1; i++ ){
    y = y*i%MOD;
  }
  return x*continuous_pow(y, MOD-2)%MOD;
}

// long long combination(long long n,long long m){
//     long long a1=1,a2=1;
//     for(int i=n;i>=n-m+1;i--){
//         a1=a1*i%MOD;
//     }
//     for(int i=2;i<=m;i++){
//         a2=a2*i%MOD;
//     }

//     return a1*continuous_pow(a2,MOD-2)%MOD;
// }


int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    //calculate 2^n -1
    long long flower_num = continuous_pow(2, n) -1;

    // exclude two 
    long long aa = combination(n, a);
    long long bb = combination(n, b);
    long long ans = ((flower_num-aa-bb)%MOD+MOD)%MOD;
    long long ans2 = flower_num - aa - bb;

    // 計算例
    cout << ans << endl;
}
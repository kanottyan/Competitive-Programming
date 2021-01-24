//https://atcoder.jp/contests/jsc2019-final/tasks/jsc2019_final_a

#include <bits/stdc++.h>
#include <complex>
#include <cmath>
using namespace std;

const double PI = std::acos(-1.0);

// Cooley-Turkey FFT algorithm
vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false){
    int n = a.size();
    int h = 0; // h = log_2(n);
    for(int i=0; (1<<i)<n; ++i) h++;
    // バタフライ演算用の並べ替え(ビットリバース)
    for(int i=0; i<n; i++){
        int j=0;
        for(int k=0; k<h; k++){
            //(i>>k&1) で i の第 k 桁を取ってきて、それをビットシフトで第 h−1−k 桁にして、j との bitwise-or を取っている
            j |= (i >> k & 1) << (h-1-k);
        }
        if(i < j){
            swap(a[i], a[j]);
        }
    }

    //バタフライ演算(bはブロック数)
        //第log_2(n) + 1段
        //最初のステップを第 0 ステップとすると、第 s ステップでは、長さ 2^(s+1) のブロックがある
        // ブロックサイズ　= b *2
    for(int b=1; b <n; b *= 2){
        //各ステップでのバタフライ演算処理
        for(int j=0; j<b; ++j){
            //ブロック内j個目
            //重みw = (1の原始2b乗根のj乗), e^{-i*(2pij)/(2b)}が２つ目の引数
            complex<double> w = polar(1.0, -(2*PI)/(2*b) *j* (inverse ? -1 : 1) );
            //全ブロックに対する処理
            for(int k=0; k<n; k += b*2){
                //kを先頭とするブロック
                complex<double> s = a[j+k]; //前
                complex<double> t = a[j+k+b]*w; //後ろ
                a[j+k] = s + t; //前の更新後
                a[j+k+b] = s - t; //後ろの更新後
            }
        }
    }
    if(inverse){
        for(int i=0; i<n; i++){
            a[i] /= n;
        }
    }
    return a;
}
//実際使うときはvector<double>の入力が多いのでdoubleにも対応
vector<complex<double>> fft(vector<double> a, bool inverse = false){
    vector<complex<double>> a_complex(a.size());
    for(int i=0; i<a.size(); ++i){
        a_complex[i] = complex<double>(a[i], 0);
    }
    return fft(a_complex, inverse);
}

//FFT による畳込みO(NlongN)
vector<double> convolve(vector<double> a, vector<double> b){
    int s = a.size() + b.size() - 1; //畳み込み結果のサイズ
    int t = 1; //FFTにつかう配列のサイズ(2の累乗)
    while(t < s) t *= 2;
    a.resize(t); //FFT使えるようにサイズをｔに変換して0を詰める
    b.resize(t);
    vector<complex<double>> A = fft(a);
    vector<complex<double>> B = fft(b);
    for(int i=0; i<t; i++){
        A[i] *= B[i]; //畳み込みの結果のFFTの結果
    }
    A = fft(A, true); //IFFTで畳み込み結果を得る
    a.resize(s); // 畳み込み結果を入れるためにリサイズ
    for(int i=0; i<s; ++i){
        a[i] = A[i].real();
    }
    return a;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<double> A(N);
    vector<double> B(M);

    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<M; ++i) cin >> B[i];

    vector<double> Ap(1000000+1);
    vector<double> Bp(1000000+1);
    for(int i=0; i<N; ++i) Ap[A[i]]++;
    for(int i=0; i<M; ++i) Bp[B[i]]++;

    vector<double> ans = convolve(Ap, Bp);

    int match_num = -1;
    for(int i=0; i<ans.size(); ++i){
        if((int)(ans[i] + 0.5) >= 2){
            match_num = i;
            break;
        }
    }

    if(match_num == -1){
        cout << -1 << endl;
    }else{
        unordered_map<int, int> m;
        int cnt = 0;
        for(int i=0; i<N; ++i){
            int left = match_num - A[i];
            if(left <= 0) continue;
            m.emplace(left, i);
        }
        for(int j=0; j<M; ++j){
            if(m.count(B[j]) >= 1 && cnt < 2){
                cnt++;
                cout << m[B[j]] << " " << j << " " << endl;
                if(cnt == 2) break;
            }
        }
    }
}
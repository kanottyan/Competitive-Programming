// //http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp

// // by Geeks for geeks
// //https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// #include <vector>
// #include <iostream>

// using namespace std;


// // Binary  search (noth boundaries in the caller)
// int CeilIndex(vector<int> &v, int l, int r, int key){
//     while(r - l > 1){
//         int m = l + (r -l) / 2;
//         if(v[m] >= key)
//             r = m;
//         else
//             l = m;
//     }
//     return r;
// }

// int LongestIncreasingSubsequenceLength(vector<int> &v){
//     if(v.size() == 0){
//         return 0;
//     }

//     vector<int> tail(v.size(), 0);
//     int length = 1; // always points empty slot in tail
    
//     tail[0] = v[0];
//     for (size_t i = 1; i < v.size(); i++) { 
  
//         // new smallest value 
//         if (v[i] < tail[0]) 
//             tail[0] = v[i]; 
  
//         // v[i] extends largest subsequence 
//         else if (v[i] > tail[length - 1]) 
//             tail[length++] = v[i]; 
  
//         // v[i] will become end candidate of an existing 
//         // subsequence or Throw away larger elements in all 
//         // LIS, to make room for upcoming grater elements 
//         // than v[i] (and also, v[i] would have already 
//         // appeared in one of LIS, identify the location 
//         // and replace it) 
//         else
//             tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
//     } 
//     return length;

// }

// int main() 
// { 
// //    int org_data[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6};      // 元データ
//     int org_data[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};      // 元データ

//     std::vector<int> v(org_data, end(org_data));     // 元データから動的配列を生成
//     cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequenceLength(v) << '\n'; 
//     return 0; 
// } 



// //インラインDPでLISを解く
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// const long long INF = 1LL << 60;

// int LIS(const vector<long long> &a){
//     int N = (int)a.size();
//     vector<long long> dp(N, INF);
//     for(int i=0; i<N; ++i){
//         //dp[k] >= a[i]となる最小のイテレータ
//         auto it = lower_bound(dp.begin(), dp.end(), a[i]);

//         *it = a[i];
//     }

//     //dp[k] < INF となる最大のkに対して k+1が答え
//     //それはdp[k] >= INF　となる最小のkに一致
//     return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

// }

// int main(){
//     int N;
//     cin >> N;
//     vector<long long> a(N);
//     for(int i=0; i<N; ++i) cin >> a[i];
//     cout << LIS(a) << endl;
// }

//By SegTree

//けんちょんスタイル
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional>

// using namespace std;

// //抽象化したセグ木
// template<class Monoid> class SegTree {
//     using Func = Function<Monoid(Monoid, Monoid)>
//     const Func F;
//     const Monoid UNITY;
//     int SEZR_R;
//     vector<Monoid> dat;

//     SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity){
//         init(n);
//     }
//     void init(int n) {
//         SIZE_R = 1;
//         while(SIZE_R < n) SIZE_R *= 2;
//         dat.assign(SIZE_R * 2, UNITY)
        
//     }

//     /*set , a is 0-indexed */
//     void set(int a, const Monoid &v) {
//         dat[a + SIZE_R] = v;
//     }

//     void build(){
//         for(int k = SIZE_R -1; k >0; --k){
//             dat[k] = F(dat[k*2], dat[k*2+1]);
//         }
//     }

//     /* update a, a is 0-indexed */
//     void update(int a, const Monoid &v) {
//         int k = a + SIZE_R;
//         dat[k] = v;
//         while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
//     }
    
//     /* get [a, b), a and b are 0-indexed */
//     Monoid get(int a, int b) {
//         Monoid vleft = UNITY, vright = UNITY;
//         for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
//             if (left & 1) vleft = F(vleft, dat[left++]);
//             if (right & 1) vright = F(dat[--right], vright);
//         }                                                                                                              
//         return F(vleft, vright);
//     }

//      inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

//          /* debug */
//     void print() {
//         for (int i = 0; i < SIZE_R; ++i) {
//             cout << (*this)[i];
//             if (i != SIZE_R-1) cout << ",";
//         }
//         cout << endl;
//     }
// }

// -----
// 自分の書いてセグ木
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

template <class T> class SegTree {
    int n;                          // 葉の数
    vector<T> data;                 // データを格納するvector
    T def;                          // 初期値かつ単位元
    function<T(T, T)> operation;    // 区間クエリで使う処理
    function<T(T, T)> update;       // 点更新で使う処理

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r){
        // 交差しない場合
        if(r <= a || b <= l) return def; 
        //// a,l,r,bの順で完全に含まれる
        if (a <= l && r <= b){
            return data[k]; 
        }else{
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }
    public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    //コンストラクタ
    SegTree(size_t _n, T _def, 
                    function<T(T, T)> _operation, 
                    function<T(T, T)> _update)
                    :def(_def), operation(_operation), update(_update){
        n=1;
        while(n < _n){
            n *= 2;
        }
        data = vector<T>(2*n -1, def);
    }

    //区間クエリ
    T query(int a, int b){
        return _query(a, b, 0, 0, n);
    }

    //更新クエリ:場所i(0-indexed)の値をxで更新
    void change(int i, T x){
        i += n -1;
        data[i] = update(data[i], x);
        while(i > 0){
            i = (i-1)/2;
            data[i] = operation(data[i*2+1], data[i*2+2]);
        }
    }

    // 添字でアクセス
    T operator[](int i){
        return data[i + n -1];
    }
};

int LIS(const vector<long long> &a){
    int N = (int)a.size();
    
    //座圧
    vector<long long> aval;
    for(int i=0; i<N; ++i){
        aval.push_back(a[i]);
        sort(aval.begin(), aval.end());
        aval.erase(unique(aval.begin(), aval.end()), aval.end());
    }

    //セグ木
    SegTree<long long> st(N, 0, [](long long a, long long b) { return max(a, b); },
                      [](long long a, long long b) { return b; });
    
    //更新 
    int res = 0;
    for(int i=0; i<N; ++i){
        //a[i]が何番目か
        auto lowlow = lower_bound(aval.begin(), aval.end(), a[i]);
        auto bb = aval.begin();
        int h = lowlow - bb;

        //値取得
        int A = st.query(0, h);

        //更新
        if(st.query(h, h+1) < A +1){
            st.change(h, A+1);
            res= max(res, A+1);
        }
    }
    return res;
}

int main(){
    int N; cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; ++i){
        cin >> a[i];
    }
    cout << LIS(a) << endl;
}

//-------

// by DP O(N^2)
// #include <bits/stdc++.h> 
// using namespace std; 
  
// // Function to return the size of the 
// // longest increasing subsequence 
// int LISusingLCS(vector<int>& seq) 
// { 
//     int n = seq.size(); 
  
//     // Create an 2D array of integer 
//     // for tabulation 
//     vector<vector<int> > L(n + 1, vector<int>(n + 1)); 
  
//     // Take the second sequence as the sorted 
//     // sequence of the given sequence 
//     vector<int> sortedseq(seq); 
  
//     sort(sortedseq.begin(), sortedseq.end()); 
  
//     // Classical Dynamic Programming algorithm 
//     // for Longest Common Subsequence 
//     for (int i = 0; i <= n; i++) { 
//         for (int j = 0; j <= n; j++) { 
//             if (i == 0 || j == 0) 
//                 L[i][j] = 0; 
  
//             else if (seq[i - 1] == sortedseq[j - 1]) 
//                 L[i][j] = L[i - 1][j - 1] + 1; 
  
//             else
//                 L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
//         } 
//     } 
  
//     // Return the ans 
//     return L[n][n]; 
// } 
  
// // Driver code 
// int main() 
// { 

//     vector<int> sequence;
//     sequence.push_back(12);
//     sequence.push_back(34);
//     sequence.push_back(1);
//     sequence.push_back(5);
//     sequence.push_back(40);
//     sequence.push_back(80);

//     cout << LISusingLCS(sequence) << endl; 

//     return 0; 
// } 
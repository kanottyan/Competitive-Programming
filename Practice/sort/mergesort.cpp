#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int> &a, int left, int right){
    if(right - left ==1)return;
    int mid = left + (right - left)/2;

    // [left, mid)
    MergeSort(a, left, mid );
    // [mid, right)
    MergeSort(a, mid, right);

    //copy left and right data, right side is inversed.
    vector<int> buf;
    for(int i=left; i <mid; ++i) buf.push_back(a[i]);
    for(int i=right-1; i>=mid; --i) buf.push_back(a[i]);

    //compare the left side and right side value, put the smaller one to the head.
    int iterator_left = 0;
    int iterator_right = (int)buf.size() -1;

    for(int i=left; i<right; ++i){
        //take left
        if(buf[iterator_left] <= buf[iterator_right]){
            a[i] = buf[iterator_left++];
        }
        //take right
        else{
            a[i] = buf[iterator_right--];
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    MergeSort(a, 0, n);

    return 0;
}
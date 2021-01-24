#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &a, int left, int right){
    if(right - left <= 1)return;

    int pivot_idx = left + rand() % (right-left);
    //int pivot_idx = (right + left)/2;
    int pivot = a[pivot_idx];

    //swap pivot and right side
    swap(a[pivot_idx], a[right-1]);

    int i = left; // iterator
    for(int j=left; j<right-1; ++j){
        if(a[j] < pivot){
            //if smaller than the pivot, then put into the left, and move i ahead
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[right-1]); //put pivot into the i place.

    // now pivot is fixed, then check the left and right of the pivot.
    // note pivot is fixed so we should not include pivot_idx == i
    //rec steps 
    QuickSort(a, left, i);
    QuickSort(a, i+1, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    /* 挿入前の配列を出力してみる */
    cout << "Before: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;

    QuickSort(a, 0, n);

    /* 挿入後の配列を出力してみる */
    cout << "After: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;

    return 0;
}
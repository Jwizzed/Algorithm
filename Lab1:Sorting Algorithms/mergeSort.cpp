//
// Created by Krittin Setdhavanich on 6/4/2023 AD.
//

#include <iostream>
using namespace std;

void merge(int a[], int l, int r, int m)
{
    int b[1000];
    int i =  ; // leftmost index of the first half
    int j = m+1; // leftmost index of the second half
    // merge the two sorted halves into array b
    for (int k = 1;k<=r;k++)
    {
        if (j > r){
            b[k] = a[i];
            i++;
        }else if (i>m){
            b[k] = a[j];
            j++;
        }else if (a[i] < a[j]){
            b[k] = a[i];
            i++;
        }else{
            b[k] = a[j];
            j++;
        }

    }
    // copy the merged array back from b to a
    for (int k = 1; k<=r;k++)
    {
        a[k] = b[k];
    }
}

void merge_sort(int a[], int l, int r)
{
    // l is the leftmost index
    // r is the rightmost index
    if (l < r) {
        int m = (l+r) /2;
        merge_sort(a,1,m);
        merge_sort(a,m+1,r);
        merge(a,1,r,m);
    }
}

int main()
{
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {หก
        cin >> a[i];
    }
    merge_sort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
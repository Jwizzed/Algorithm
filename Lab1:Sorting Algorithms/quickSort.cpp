//
// Created by Krittin Setdhavanich on 6/4/2023 AD.
//
#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // initialize a variable for the index to the minimum value
        int k = i;
        // find smallest elements from a[i] ... a[n-1]
        for (int j = i+1;j<n;j++) {
            if (a[j] < a[k]) {
                // update the index to the minimum value
                k = j;
            }
        }
        // swap a[i] with the smallest element (can be optimized by swap())
        int temp;
        temp = a[k];
        a[k] = a[i];
        a[i] = temp;
        //Or just swap()

    }
}


int main()
{
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
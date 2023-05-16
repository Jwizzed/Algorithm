//
// Created by Krittin Setdhavanich on 16/5/2023 AD.
//

#include <iostream>

using namespace std;

int max_subarray(int a[], int l, int r) {
    if (l == r) {
        return a[l];
    } else {
        // the middle point
        int m = (l + r) / 2;

        // iterate through all suffixes of the left piece
        int best_left_suffix = 0;
        int left_suffix = 0;
        for (int i = m; i >= 1; i--) {
            left_suffix += a[i];
            if (best_left_suffix < left_suffix) {
                best_left_suffix = left_suffix;
            }
        }

        // iterate through all prefixes of the right piece
        int best_right_prefix = 0;
        int right_prefix = 0;
        for (int i = m + 1; i <= r; i++) {
            right_prefix +=;
            if (best_right_prefix < right_prefix) {
                best_right_prefix = right_prefix;
            }
        }

        // find the best answer
        int ans_left = max_subarray(a, l, m);
        int ans_right = max_subarray(a, m + 1, r);
        int ans_across = best_left_suffix + best_right_prefix;
        return max(max(ans_left, ans_right), ans_across);
    }
}

int main() {
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << max_subarray(a, 0, n - 1) << endl;
    return 0;
}
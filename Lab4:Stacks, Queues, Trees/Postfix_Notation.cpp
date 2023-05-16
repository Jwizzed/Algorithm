//
// Created by Krittin Setdhavanich on 16/5/2023 AD.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    stack<int> s;
    string item;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> item;
        if (item.compare("+") == 0) {
            int temp_1 = s.top();
            s.pop();
            int temp_2 = s.top();
            s.pop();
            s.push(temp_2 + temp_1);
        } else if (item.compare("-") == 0) {
            int temp_1 = s.top();
            s.pop();
            int temp_2 = s.top();
            s.pop();
            s.push(temp_2 - temp_1);
        } else if (item.compare("*") == 0) {
            int temp_1 = s.top();
            s.pop();
            int temp_2 = s.top();
            s.pop();
            s.push(temp_2 * temp_1);
        } else if (item.compare("/") == 0) {
            int temp_1 = s.top();
            s.pop();
            int temp_2 = s.top();
            s.pop();
            s.push(temp_2 / temp_1);
        } else {
            // stoi converts string to integer
            int val = stoi(item);
            s.push(val);
        }
    }

    cout << s.top() << endl;
    return 0;
}
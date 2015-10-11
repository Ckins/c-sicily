#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

stack<int> res;
int couple[200020];

int main() {
    int n;
    cin >> n;
    while (n!=0) {
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            couple[a] = b;
            couple[b] = a;
        }

        for (int i = 1; i <= n*2; i++) {
            if ((!res.empty()) && res.top() == couple[i]) {
                res.pop();
            } else {
                res.push(i);
            }
        }
        if (res.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        while (!res.empty()) {
            res.pop();
        }
        cin >> n;
    }
}
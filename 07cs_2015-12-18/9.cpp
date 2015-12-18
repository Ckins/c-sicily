#include <iostream>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <stdio.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int res = 0;
        cin >> res;
        char c;
        while (cin >> c && c != '.') {
            int tmp;
            if (c == '+') {
                cin >> tmp;
                res += tmp;
            } else if (c == '-') {
                cin >> tmp;
                res -= tmp;
            } else if (c == '*') {
                cin >> tmp;
                res *= tmp;
            } else {
                cin >> tmp;
                res /= tmp;
            }
        }
        cout << res << endl;
    }
}
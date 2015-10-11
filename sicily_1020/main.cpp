#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int bas[120];
    int res[120];
    int total;
    cin >> total;
    while (total--) {
        cin >> n;
        for (int i = 0; i < n ;i++) {
            cin >> bas[i];
        }
        string str;
        cin >> str;
        for (int i = 0; i < n; i++) {
            int length = str.length();
            res[i] = 0;
            int j = 0;
            for (j = 0; j < str.length(); j++) {
                res[i] = (res[i]*10 + (str[j]-'0')) % bas[i];
            }
        }

        cout << "(";
        for (int i = 0; i< n; i++) {
            cout << res[i];
            if (i != n-1) {
                cout << ",";
            } else {
                cout << ")";
            }
        }
        cout << endl;
    }
    return 0;
}


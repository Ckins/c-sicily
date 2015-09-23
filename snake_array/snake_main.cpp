#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    int a[n][n];
    int i = 0;
    int j = 0;
    int count = 1;

    cout << "snake_array" << endl;
    for (i = 1; i <= n; i++) {
        if (i%2 != 0) {
            for (j = i/2; j < n-(i/2);j++) {
                a[i/2][j] = count;
                count++;
            }
            for (j = 1+i/2; j < n-i/2; j++) {
                a[j][n-i/2-1] = count;
                count++;
            }
        } else {
            for (j = n-i/2-1; j >= i/2-1; j--) {
                a[n-i/2][j] = count;
                count++;
            }
            for (j = n-1-i/2; j >= i/2; j--) {
                a[j][i/2-1] = count;
                count++;
            }
        }
    }

    for (i = 0;i < n;i++) {
        for (j = 0; j < n; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}


#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    int a[n][n];
    int i = 0;
    int j = 0;
    int count = 1;

    for (i = 1; i <= n; i++) {
        if (i%2 != 0) {
            for (j = i/2; j < n-(i/2);j++) {
                a[i/2][j] = count;
                count++;
            }
            for (j = 1+i/2; j < n-i/2; j++) {
                a[j][n-i/2] = count;
                count++;
            }
        } else {
            for (j = n-i/2; j >= i/2-1; j--) {
                a[n-i/2][j] = count;
                count++;
            }
            for (j = n-1-i/2; j >= i/2; j--) {
                a[j][i/2-1] = count;
                count++;
            }
        }
    }

    return 0;
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;
//大数求余,对bi（基）进行逐个计算
//1%m   = 1
//12%m  = (1 * 10+2) %m = (1%m * 10+2) %m
//123%m = (12 * 10+3)%m = (12%m * 10+3)%m
//1234567890123456789 % m
//=((1%m * 10 + 2) %m * 10 + 3)%m * 10....

int div(string x, int b) {
    int a = 0;
    for (int i = 0; x[i] != '\0'; i++) {
        a = (a * 10 + x[i] - '0') % b;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int b[101], r[101];
        int n; 
        char x[401];

        cin >> n;
        for (int i = 0; i < n; ++i)
            cin>>b[i];
        cin >> x;
        cout << '(';
        for (int i = 0; i < n-1; ++i) {
            r[i] = div(x, b[i]);
            cout << r[i] << ',';
        }
        r[n-1] = div(x, b[n-1]);
        cout << r[n-1] << ')' << endl;
    }
    return 0;
}

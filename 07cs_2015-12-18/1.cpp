#include<iostream>

using namespace std;

bool is_odd(int num) {
    return (num%2 == 1);
}

void sort_increase(int* a, int len) {
    int min = a[0];
    int seq = 0;
    for (int i = 0; i < len; i++) {
        min = a[i];
        seq = i;
        for (int j = i+1; j < len; j++) {
            if (a[j] < min) {
                seq = j;
                min = a[j];
            }
        }
        int tmp = a[i];
        a[i] = a[seq];
        a[seq] = tmp;
    }
}

void sort_decrease(int* a, int len) {
    int max;
    int seq = 0;
    for (int i = 0; i < len; i++) {
        max = a[i];
        seq = i;
        for (int j = i+1; j < len; j++) {
            if (a[j] > max) {
                seq = j;
                max = a[j];
            }
        }
        int tmp = a[i];
        a[i] = a[seq];
        a[seq] = tmp;
    }
}

int main() {
    int total;
    cin >> total;
    while (total--) {
        int odd_array[100];
        int even_array[100];

        int n;
        int odd_ = 0;
        int even_ = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (is_odd(tmp)) {
                odd_array[odd_++] = tmp;
            } else {
                even_array[even_++] = tmp;
            }
        }

        sort_increase(odd_array, odd_);
        sort_decrease(even_array, even_);

        for (int i = 0; i < odd_; i++) {
            if (i != 0 ) cout << " " << odd_array[i];
            else cout << odd_array[i];
        }

        for (int i = 0; i < even_; i++) {
            if (odd_ != 0 ) cout << " " << even_array[i];
            else cout << even_array[i];
        }
        cout << endl;
    }
}

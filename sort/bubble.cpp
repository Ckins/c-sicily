#include <iostream>

using namespace std;

int main() {
      int arr[5];
      int n = 5;
      for (int i = 0; i < 5; i++) {
            cin >> arr[i];
      }
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
      for (int i = 0; i < 5; i++) {
           cout << arr[i] << " ";
      }
      cout << endl;
}


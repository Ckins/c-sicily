#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int a[5];
  for (int i = 0; i < 5; i++) cin >> a[i];
  
  int i;
  // selection sort
  for (int j = 0; j < 5; j++) {
    int iMin = j;
    for (i = j+1; i < 5; i++) {
      if (a[i] < a[iMin]) {
        iMin = i;
      }
    }
    if (iMin != j) {
        swap(a[j], a[iMin]);
    }
  }

  for (int i = 0; i < 5; i++) cout << a[i] << " ";
  cout << endl;
}

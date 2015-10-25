#include <iostream>
#include <cmath>

using namespace std;

const int INFINITE = 1000000;
int maxArray[1000][1000];
int numberArray[1000];

int dp(int begin, int end) {
  if (begin + 1 == end) {
    return abs(numberArray[end] - numberArray[begin]);
  } else if (maxArray[begin][end] != INFINITE) {
    return maxArray[begin][end];
  } else {
    int temp1;
    int temp2;

      // the best one choice the begin
    if (numberArray[begin + 1] >= numberArray[end]) {
      temp1 = numberArray[begin] - numberArray[begin + 1] + dp(begin + 2, end);
    } else {
      temp1 = numberArray[begin] - numberArray[end] + dp(begin + 1, end - 1);
    }

      // the best one choice the end
    if (numberArray[begin] >= numberArray[end - 1]) {
      temp2 = numberArray[end] - numberArray[begin] + dp(begin + 1, end - 1);
    } else {
      temp2 = numberArray[end] - numberArray[end - 1] + dp(begin, end - 2);
    }

    maxArray[begin][end] = max(temp1, temp2);
  }

  return maxArray[begin][end];
}

int main(int argc, char* argv[]) {
  int n;
  int count = 1;

  while (cin >> n && n != 0) {
    for (int i = 0; i < n; ++i) {
      cin >> numberArray[i];
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        maxArray[i][j] = INFINITE;
      }
    }

    cout << "In game " << count++ <<", the greedy strategy might lose by as many as "
         << dp(0, n - 1) << " points.\n";
  }
  return 0;
}
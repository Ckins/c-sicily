#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

bool isVisited[40320];

struct triTree {
  int magic[2][4];
  int count;
  string operation;

  triTree() {
    count = 0;
    operation = "";
  }

  triTree(int magic[][4], int count = 0, string operation = "") {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 4; ++j) {
        this -> magic[i][j] = magic[i][j];
      }
    }

    this -> count = count;
    this -> operation = operation;
  }
};

bool isTarget(int magic[][4], int target[][4]) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (magic[i][j] != target[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int fact(int n) {
  int sum = 1;

  for (int i = 1; i <= n; ++i) {
    sum *= i;
  }

  return sum;
}

int cantor(int map[][4]) {
  int arr[8] = {0};
  int hash[8] = {0};

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      arr[i * 4 + j] = map[i][j];
    }
  }

  for (int i = 0; i < 8; ++i) {
    int temp = 7 - i;

    for (int j = i; j < 8; ++j) {
      if (arr[j] > arr[i]) {
        temp--;
      }
    }

    hash[arr[i] - 1] = temp;
  }

  int sum = 0;

  for (int i = 0; i < 8; ++i) {
    sum += hash[i] * fact(i);
  }

  return sum;
}

void operationA(const triTree& root, triTree& target) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      target.magic[i][j] = root.magic[(i + 1) % 2][j];
    }
  }

  target.count = root.count + 1;
  target.operation = root.operation + 'A';
}

void operationB(const triTree& root, triTree& target) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      target.magic[i][j] = root.magic[i][(j + 3) % 4];
    }
  }

  target.count = root.count + 1;
  target.operation = root.operation + 'B';
}

void operationC(const triTree& root, triTree& target) {
  target.magic[0][0] = root.magic[0][0];
  target.magic[0][1] = root.magic[1][1];
  target.magic[0][2] = root.magic[0][1];
  target.magic[0][3] = root.magic[0][3];
  target.magic[1][0] = root.magic[1][0];
  target.magic[1][1] = root.magic[1][2];
  target.magic[1][2] = root.magic[0][2];
  target.magic[1][3] = root.magic[1][3];

  target.count = root.count + 1;
  target.operation = root.operation + 'C';
}

int main( int argc, char* argv[]) {
  int step;

  while (cin >> step && step != -1) {
    queue<triTree> q;
    int target[2][4];
    int magic[2][4] = {{1, 2, 3, 4}, {8, 7, 6, 5}};
    triTree root(magic);

    memset(isVisited, false, sizeof(isVisited));
    isVisited[cantor(magic)] = true;

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> target[i][j];
      }
    }

    q.push(root);

    bool isFind = false;

    while (!q.empty()) {
      if (q.front().count > step) {
        break;
      } else if (isTarget(q.front().magic, target)) {
        cout << q.front().count << ' ' << q.front().operation << endl;
        isFind = true;
        break;
      } else {
        triTree treeA;
        triTree treeB;
        triTree treeC;

        operationA(q.front(), treeA);
        operationB(q.front(), treeB);
        operationC(q.front(), treeC);

        if (!isVisited[cantor(treeA.magic)]) {
          q.push(treeA);
          isVisited[cantor(treeA.magic)] = true;
        }

        if (!isVisited[cantor(treeB.magic)]) {
          q.push(treeB);
          isVisited[cantor(treeB.magic)] = true;
        }

        if (!isVisited[cantor(treeC.magic)]) {
          q.push(treeC);
          isVisited[cantor(treeC.magic)] = true;
        }

        q.pop();
      }
    }

    if (!isFind) {
      cout << -1 << endl;
    }
  }

  return 0;
}
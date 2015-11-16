#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

struct position {
  int x;
  int y;

  position(int x = 0, int y = 0) : x(x), y(y) {}

  position(const position& pos) {
    x = pos.x;
    y = pos.y;
  }
};

bool isVisited[5][6];
position path[30];

const position direction[8] = {
  position(1, -2), position(2, -1),
  position(2, 1), position(1, 2),
  position(-1, 2), position(-2, 1),
  position(-2, -1), position(-1, -2)
};

bool isValid(const position& pos) {
  return pos.x >= 0 && pos.x < 5 && pos.y >= 0 && pos.y < 6;
}

void dfs(position pos, int count, bool& isEnd) {
  if (count >= 30) {
    isEnd = true;
    return;
  }

  for (int i = 0; i < 8; ++i) {
    position temp(pos.x + direction[i].x, pos.y + direction[i].y);

    if (isValid(temp) && !isVisited[temp.x][temp.y]) {
      path[count] = temp;
      isVisited[temp.x][temp.y] = true;

      dfs(temp, count + 1, isEnd);

      if (isEnd) {
        return;
      } else {
        isVisited[temp.x][temp.y] = false;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int begin;

  while (cin >> begin && begin != -1) {
    memset(isVisited, false, sizeof(isVisited));

    position start((begin - 1) / 6, (begin - 1) % 6);
    path[0] = start;
    isVisited[start.x][start.y] = true;

    bool isEnd = false;

    dfs(start, 1, isEnd);

    for (int i = 0; i < 30; ++i) {
      if (i == 0) {
        cout << path[i].x * 6 + path[i].y + 1;
      } else {
        cout << ' ' << path[i].x * 6 + path[i].y + 1;
      }
    }

    cout << endl;
  }

  return 0;
}

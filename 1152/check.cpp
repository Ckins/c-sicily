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

const position direction[8] = {
  position(1, -2), position(2, -1),
  position(2, 1), position(1, 2),
  position(-1, 2), position(-2, 1),
  position(-2, -1), position(-1, -2)
};

bool isValid(const position& pos) {
  return pos.x >= 0 && pos.x < 5 && pos.y >= 0 && pos.y < 6;
}

int main() {
    int total =30;
    while (total--) {
        int state[30];
        memset(isVisited, false, sizeof(isVisited));

        for (int i = 0; i < 30; i++) cin >> state[i];
        bool vaild = false;
        for (int i = 0; i < 29; i++) {
            position pos((state[i]-1)/6, (state[i]-1)%6);
            position next((state[i+1]-1)/6, (state[i+1]-1)%6);
            vaild =false;
            for (int j = 0; j < 8; ++j) {
                position temp(pos.x + direction[j].x, pos.y + direction[j].y);
                if (temp.x == next.x && temp.y == next.y) {
                    vaild = true;
                    break;
                }
            }
            if (!vaild) {
                cout << "In";
                break;
            }
        }
        cout << "valid" << endl;
    }
}

#define POS_NUM 64
#define X_DOWN 0
#define X_UP 8
#define Y_DOWN 0
#define Y_UP 8

#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

bool chess_board[X_UP][Y_UP];
bool reach_end;
int travel_path[POS_NUM];

struct position {
    int x;
    int y;
    int next;

    position(int cur_x = 0, int cur_y = 0, int next_num = 0) : x(cur_x), y(cur_y), next(next_num) {}

    bool operator < (const position &a) const {return next < a.next;}
};

const position direction[8] = {
    position(-2, -1), position(-1, -2),
    position(-1, 2), position(-2, 1),
    position(1, -2), position(2, -1),
    position(2, 1), position(1, 2)
};

bool isValid(const position& pos) {
  return pos.x >= X_DOWN && pos.x < X_UP && pos.y >= Y_DOWN && pos.y < Y_UP;
}

void try_move(int x, int y, int steps) {
    if (reach_end) return;

    if (steps >= POS_NUM-1) {
        reach_end = true;
        printf("%d", travel_path[0]);
        for (int i = 1; i < POS_NUM;i++) {
            printf(" %d", travel_path[i]);
        }
        printf("\n");
        return;
    }

    int n = 0;
    position p[8];
    for (int dir = 0; dir < 8; dir++) {
        int xx = x + direction[dir].x;
        int yy = y + direction[dir].y;
        if (xx >= 0 && yy >= 0 && xx < X_UP && yy < Y_UP && !chess_board[xx][yy]) {
            p[n].x = xx;
            p[n].y = yy;
            p[n].next = 0;
            for (int tdir = 0; tdir < 8; tdir++) {
                int xxx = xx + direction[tdir].x;
                int yyy = yy + direction[tdir].y;
                if (xxx >= 0 && yyy >= 0 && xxx < X_UP && yyy < Y_UP) {
                    if (!chess_board[xxx][yyy]) p[n].next++;
                }
            }
            n++;
        }
    }
    sort(p, p + n);
    for (int j = 0; j < n; j++) {
        chess_board[p[j].x][p[j].y] = true;
        travel_path[steps + 1] = p[j].x * X_UP + p[j].y + 1;
        try_move(p[j].x, p[j].y, steps + 1);
        chess_board[p[j].x][p[j].y] = false;
    }

}

int main() {
    int start;
    while (cin>>start && start!=-1) {
        reach_end = false;
        memset(chess_board, false, sizeof(chess_board));
        int x = (start-1) / X_UP;
        int y = (start-1) % Y_UP;
        travel_path[0] = start;
        chess_board[x][y] = true;
        try_move(x, y, 0);
    }
    return 0;
}

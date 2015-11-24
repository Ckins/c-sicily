#include<cstring>
#include<stdio.h>
#include<iostream>
#include<algorithm>

#define WIDTH 8
#define HIGHT 8

using namespace std;

bool map[HIGHT][WIDTH], flag;
int ans[WIDTH * HIGHT];
int arrow[8][2] = {{-2, -1} , {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

struct point{
    int x, y, nextPointsNum;
    bool operator < (const point &a) const {return nextPointsNum < a.nextPointsNum;};
};

void dfs(int x, int y, int i) {
    cout << i << endl;
    if (flag) return;
    if (i >=  WIDTH * HIGHT - 1) {
        for (int j = 0; j < WIDTH * HIGHT - 1; j++) { 
            printf("%d ", ans[j]);
        }
        printf("%d\n", ans[WIDTH * HIGHT - 1]);
        
        flag = 1;
        return;
    }
    int n = 0;
    point p[8];
    for (int dir = 0; dir < 8; dir++) {
        int xx = x + arrow[dir][0];
        int yy = y + arrow[dir][1];
        if (xx >= 0 && yy >= 0 && xx < HIGHT && yy < WIDTH && !map[xx][yy]) {
            p[n].x = xx;
            p[n].y = yy;
            p[n].nextPointsNum = 0;
            for (int tdir = 0; tdir < 8; tdir++) {
                int xxx = xx + arrow[tdir][0];
                int yyy = yy + arrow[tdir][1];
                if (xxx >= 0 && yyy >= 0 && xxx < HIGHT && yyy < WIDTH) {
                    if (!map[xxx][yyy]) p[n].nextPointsNum++;
                }
            }
            n++;
        }
    }
    sort(p, p + n);
    for (int j = 0; j < n; j++) {
        map[p[j].x][p[j].y] = 1;
        ans[i + 1] = p[j].x * WIDTH + p[j].y + 1;
        dfs(p[j].x, p[j].y, i + 1);
        map[p[j].x][p[j].y] = 0;
    }
}

int main() {
    int pos;
    while (cin >> pos && pos != -1) {
        flag = 0;
        ans[0] = pos;
        memset(map, 0, sizeof(map));
        int x = (pos - 1) / WIDTH;
        int y = (pos - 1) % WIDTH;
        map[x][y] = 1;
        dfs(x, y, 0);
    }
    return 0;
}
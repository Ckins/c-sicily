#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

// chessboard range from x:0-4, y:0-5

struct position {
    int x;
    int y;

    position(int cur_x, int cur_y) : x(cur_x), y(cur_y) {}

    position(const position& pos) : x(pos.x), y(pos.y) {}
};

int main(int argc, char *argv[], char *envp[]) {
    int start;
    while (scanf("%d", &start) && start != -1) {
        
    }
}
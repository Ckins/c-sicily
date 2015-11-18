#define POS_NUM 30
#define X_DOWN 0
#define X_UP 5
#define Y_DOWN 0
#define Y_UP 6

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

struct position {
    int x;
    int y;

    position(int cur_x, int cur_y) : x(cur_x), y(cur_y) {}

    position(const position& pos) : x(pos.x), y(pos.y) {}
};

const position direction[8] = {
    position(1, -2), position(2, -1),
    position(2, 1), position(1, 2),
    position(-1, 2), position(-2, 1),
    position(-2, -1), position(-1, -2)
};

bool isValid(const position& pos) {
  return pos.x >= X_DOWN && pos.x < X_UP && pos.y >= Y_DOWN && pos.y < Y_UP;
}

struct horse_state {
    int step;
    int cur_pos;
    int available;
    int route[POS_NUM];
    int visited[8];

    horse_state() {
        step = 0;
        cur_pos = 0;
        available = 0;
        memset(visited, 0, 8);
        for (int i = 0; i < POS_NUM; i++) route[i] = -1;
    }

        // calculate the available next move
    void get_grid() {
        int res = 0;
        int x = cur_pos/6;
        int y = cur_pos%6;

        for (int i = 0; i < 8; i++) {
            position new_pos = position(x+direction[i].x, y+direction[i].y);
            if (isValid(new_pos) && route[new_pos.x*6+new_pos.y] == -1) {
                visited[res] = i;
                res++;
            }
        }
        available = res;
    }

    // to construct the next state.
    horse_state(int s, int next_pos, int* rou) {
        memset(visited, 0, 8);
        step = s;
        cur_pos = next_pos;
        for (int i =0; i < POS_NUM;i++) route[i] = rou[i];
        route[cur_pos] = step;
        get_grid();
    }
};

stack<horse_state> my_stack;

void try_move() {

    int x = (my_stack.top().cur_pos)/6;
    int y = (my_stack.top().cur_pos)%6;
    int cur_route[POS_NUM];
    int origin_av = my_stack.top().available;
    int step = my_stack.top().step+1;
    for (int i = 0; i<POS_NUM; i++) {
        cur_route[i] = my_stack.top().route[i];
    }
    int visited[8];
    for (int i = 0; i < 8; i++) visited[i] = my_stack.top().visited[i];
    my_stack.pop();

    horse_state horse_states[8];
    int avi_count = 0;

    for (int i = 0; i < origin_av; i++) {

        int next_pos = (x+direction[visited[i]].x)*6+y+direction[visited[i]].y;
        horse_states[avi_count++] = horse_state(step, next_pos, cur_route);

    }

    int max_count;
    for (int i = 0; i < avi_count; i++) {
        horse_state max = horse_states[i];
        max_count = i;
        for (int j = i+1; j < avi_count; j++) {
            if (horse_states[j].available > horse_states[max_count].available) {
                max_count = j;
            } 
        }
        max = horse_states[max_count];
        horse_states[max_count] = horse_states[i];
        horse_states[i] = max;
    }

    for (int i = 0; i < avi_count; i++) {
        my_stack.push(horse_state(step,horse_states[i].cur_pos,cur_route));
    }
    //cout << my_stack.size() << endl;
}

int main() {
    int start;
    while (cin>>start && start!=-1) {
        while (!my_stack.empty()) {
            my_stack.pop();
        }
        int tmp[POS_NUM-1];
        for (int i = 0; i < POS_NUM; i++) tmp[i] = -1;
        my_stack.push(horse_state(0, start-1, tmp));

        while((!my_stack.empty()) && (my_stack.top().step != POS_NUM-1)) {
            try_move();
        }

        cout << start;
        if (!my_stack.empty()) {
            for (int i = 1; i <= POS_NUM-1; i++) {
                for (int j = 0; j <= POS_NUM-1; j++) {
                    if (my_stack.top().route[j] == i) {
                        cout << " " << j+1;
                    }
                }
            }
        } else {
            cout << "can not find";
        }
        cout << endl;
    }
    return 0;
}

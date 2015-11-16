#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

struct horse_state {
    int cur_pos;
    int route[30];
    int step;
    int available;
    int visited[8];

    horse_state() {
        cur_pos = 0;
        for (int i = 0; i < 30; i++) route[i] = -1;
        step = 0;
        available = 0;
        memset(visited, 0, 8);
    }

        // calculate the available next move
    void get_grid() {
        int res = 0;
        int x = cur_pos/6;
        int y = cur_pos%6;
        if ((x-2>=0) && (y+1 <= 5) && (route[(x-2)*6+y+1] == -1)) {
            visited[res] = 0;
            res++;
        }
        if ((x-1 >=0) && (y+2 <= 5) && (route[(x-1)*6+y+2] == -1)) {
            visited[res] = 1;
            res++;
        }

        //right
        if ((y+2 <= 5) && (x+1 <= 4) && (route[(x+1)*6+y+2] == -1)) {
            visited[res] = 2;
            res++;
        }
        //down right
        if ((x+2 <=4) && (y+1 <= 5) && (route[(x+2)*6+y+1] == -1)) {
            visited[res] = 3;
            res++;
        }

        //down
        if ((x+2 <= 4) && (y-1 >= 0)&&(route[(x+2)*6+y-1] == -1)) {
            visited[res] = 4;
            res++;
        }
        //down left
        if ((x+1 <=4) && (y-2 >= 0) && (route[(x+1)*6+y-2] == -1)) {
            visited[res] = 5;
            res++;
        }

        //left
        if ((y-2 >= 0) && (x-1 >= 0)&&(route[(x-1)*6+y-2] == -1)) {
            visited[res] = 6;
            res++;
        }
        //up_left
        if ((x-2 >=0) && (y-1 >= 0) && (route[(x-2)*6+y-1] == -1)) {
            visited[res] = 7;
            res++;
        }
        available = res;
    }

    // to construct the next state.
    horse_state(int s, int next_pos, int* rou) {
        memset(visited, 0, 8);
        step = s;
        cur_pos = next_pos;
        for (int i =0; i < 30;i++) {
            route[i] = rou[i];
        }
        route[cur_pos] = step;
        get_grid();
    }
};

stack<horse_state> my_stack;

void try_move() {

    //my_stack.top().get_grid();

    int x = (my_stack.top().cur_pos)/6;
    int y = (my_stack.top().cur_pos)%6;
    int cur_route[30];
    int origin_av = my_stack.top().available;
    int step = my_stack.top().step+1;
    for (int i = 0; i<30; i++) {
        cur_route[i] = my_stack.top().route[i];
    }
    int visited[8];
    for (int i = 0; i < 8; i++) visited[i] = my_stack.top().visited[i];
    my_stack.pop();

    horse_state horse_states[8];
    int avi_count = 0;

    for (int i = 0; i < origin_av; i++) {

        switch(visited[i]) {
            //eight possible way to move on.
            case 0:
                horse_states[avi_count++] = horse_state(step, (x-2)*6+y+1, cur_route);
                break;

            //up_right
            case 1:
                horse_states[avi_count++] = horse_state(step, (x-1)*6+y+2, cur_route);
                break;

            //right
            case 2:
                horse_states[avi_count++] = horse_state(step, (x+1)*6+y+2, cur_route);
                break;

            case 3:
                horse_states[avi_count++] = horse_state(step, (x+2)*6+y+1, cur_route);
                break;

            //down
            case 4:
                horse_states[avi_count++] = horse_state(step, (x+2)*6+y-1, cur_route);
                break;

            //down left
            case 5:
                horse_states[avi_count++] = horse_state(step, (x+1)*6+y-2, cur_route);
                break;

            //left
            case 6:
                horse_states[avi_count++] = horse_state(step, (x-1)*6+y-2, cur_route);
                break;

            //up_left
            case 7:
                horse_states[avi_count++] = horse_state(step, (x-2)*6+y-1, cur_route);
                break;
        }
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
        int tmp[29];
        for (int i = 0; i < 30; i++) tmp[i] = -1;
        my_stack.push(horse_state(0, start-1, tmp));

        int debug;

        while((!my_stack.empty()) && (my_stack.top().step != 29)) {
            try_move();
        }

        if (!my_stack.empty()) {
            for (int i = 0; i <= 29; i++) {
                for (int j = 0; j <= 29; j++) {
                    if (my_stack.top().route[j] == i) {
                        cout << j+1 << " ";
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

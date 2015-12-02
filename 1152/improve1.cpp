#include <iostream>
#include <stack>

using namespace std;

struct horse_state {
    int cur_pos;
    int route[30];
    int step;
    int available;

    horse_state() {
        cur_pos = 0;
        for (int i = 0; i < 30; i++) route[i] = -1;
        step = 0;
        available = 0;
    }

        // calculate the available next move
    void get_grid() {
        int res = 0;
        int x = cur_pos/6;
        int y = cur_pos%6;
        if ((x-2>=0) && (y+1 <= 5) && (route[(x-2)*6+y+1] == -1)) {
            res++;
        }
        if ((x-1 >=0) && (y+2 <= 5) && (route[(x-1)*6+y+2] == -1)) {
            res++;
        }

        //right
        if ((y+2 <= 5) && (x+1 <= 4) && (route[(x+1)*6+y+2] == -1)) {
            res++;
        }
        //down right
        if ((x+2 <=4) && (y+1 <= 5) && (route[(x+2)*6+y+1] == -1)) {
            res++;
        }

        //down
        if ((x+2 <= 4) && (y-1 >= 0)&&(route[(x+2)*6+y-1] == -1)) {
            res++;
        }
        //down left
        if ((x+1 <=4) && (y-2 >= 0) && (route[(x+1)*6+y-2] == -1)) {
           res++;
        }

        //left
        if ((y-2 >= 0) && (x-1 >= 0)&&(route[(x-1)*6+y-2] == -1)) {
            res++;
        }
        //up_left
        if ((x-2 >=0) && (y-1 >= 0) && (route[(x-2)*6+y-1] == -1)) {
            res++;
        }
        available = res;
    }

    // to construct the next state.
    horse_state(int s, int next_pos, int* rou) {
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

    int x = (my_stack.top().cur_pos)/6;
    int y = (my_stack.top().cur_pos)%6;
    int cur_route[30];
    int origin_av = my_stack.top().available;
    int step = my_stack.top().step+1;
    for (int i = 0; i<30; i++) {
        cur_route[i] = my_stack.top().route[i];
    }
    my_stack.pop();

    horse_state horse_states[8];
    int avi_count = 0;

    //eight possible way to move on.
    if ((x-2>=0) && (y+1 <= 5) && (cur_route[(x-2)*6+y+1] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x-2)*6+y+1, cur_route);
    }

    //up_right
    if ((x-1 >=0) && (y+2 <= 5) && (cur_route[(x-1)*6+y+2] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x-1)*6+y+2, cur_route);
    }

    //right
    if ((y+2 <= 5) && (x+1 <= 4) && (cur_route[(x+1)*6+y+2] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x+1)*6+y+2, cur_route);
    }
    //down right
    if ((x+2 <=4) && (y+1 <= 5) && (cur_route[(x+2)*6+y+1] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x+2)*6+y+1, cur_route);
    }

    //down
    if ((x+2 <= 4) && (y-1 >= 0)&&(cur_route[(x+2)*6+y-1] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x+2)*6+y-1, cur_route);
    }
    //down left
    if ((x+1 <=4) && (y-2 >= 0) && (cur_route[(x+1)*6+y-2] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x+1)*6+y-2, cur_route);
    }

    //left
    if ((y-2 >= 0) && (x-1 >= 0)&&(cur_route[(x-1)*6+y-2] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x-1)*6+y-2, cur_route);
    }
    //up_left
    if ((x-2 >=0) && (y-1 >= 0) && (cur_route[(x-2)*6+y-1] == -1)) {
        horse_states[avi_count++] = horse_state(step, (x-2)*6+y-1, cur_route);
    }

    if (origin_av != avi_count) cout << "EEEEEE" << endl;

    //cout << avi_count << endl;
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
    cin >> start;
    while (start!=-1) {
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
            cout << start;
            for (int i = 1; i <= 29; i++) {
                for (int j = 0; j <= 29; j++) {
                    if (my_stack.top().route[j] == i) {
                        cout << " " << j+1;
                    }
                }
            }
        } else {
            cout << "can not find";
        }
        cout << endl;
        cin >> start;
    }
    return 0;
}

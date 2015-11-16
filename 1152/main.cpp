#include <iostream>
#include <stack>

using namespace std;

struct horse_state {
	int cur_pos;
    int route[30];
    int step;

    horse_state() {
        cur_pos = 0;
        for (int i = 0; i < 30; i++) route[i] = -1;
        step = 0;
    }

    // to construct the next state.
    horse_state(int s, int next_pos, int* rou) {
        step = s;
        cur_pos = next_pos;
        for (int i =0; i < 30;i++) {
            route[i] = rou[i];
        }
        route[cur_pos] = step;
    }
};

stack<horse_state> my_stack;

void try_move() {

    int x = (my_stack.top().cur_pos)/6;
    int y = (my_stack.top().cur_pos)%6;
    int cur_route[30];
    int step = my_stack.top().step+1;
    for (int i = 0; i<30; i++) {
        cur_route[i] = my_stack.top().route[i];
    }
    my_stack.pop();

    //eight possible way to move on.
    //up

    if ((x-2>=0) && (y+1 <= 5) && (cur_route[(x-2)*6+y+1] == -1)) {
        my_stack.push(horse_state(step, (x-2)*6+y+1, cur_route));
    }

    //up_right
    if ((x-1 >=0) && (y+2 <= 5) && (cur_route[(x-1)*6+y+2] == -1)) {
        my_stack.push(horse_state(step, (x-1)*6+y+2, cur_route));
    }

    //right
    //cout << cur_route[x*6+y+2] << endl;
    if ((y+2 <= 5) && (x+1 <= 4) && (cur_route[(x+1)*6+y+2] == -1)) {
        my_stack.push(horse_state(step, (x+1)*6+y+2, cur_route));
    }
    //down right
    if ((x+2 <=4) && (y+1 <= 5) && (cur_route[(x+2)*6+y+1] == -1)) {
        my_stack.push(horse_state(step, (x+2)*6+y+1, cur_route));
    }

    //down
    if ((x+2 <= 4) && (y-1 >= 0)&&(cur_route[(x+2)*6+y-1] == -1)) {
        my_stack.push(horse_state(step, (x+2)*6+y-1, cur_route));
    }
    //down left
    if ((x+1 <=4) && (y-2 >= 0) && (cur_route[(x+1)*6+y-2] == -1)) {
        my_stack.push(horse_state(step, (x+1)*6+y-2, cur_route));
    }

    //left
    if ((y-2 >= 0) && (x-1 >= 0)&&(cur_route[(x-1)*6+y-2] == -1)) {
        my_stack.push(horse_state(step, (x-1)*6+y-2, cur_route));
    }
    //up_left
    if ((x-2 >=0) && (y-1 >= 0) && (cur_route[(x-2)*6+y-1] == -1)) {
        my_stack.push(horse_state(step, (x-2)*6+y-1, cur_route));
    }
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

        while((!my_stack.empty()) && (my_stack.top().step != 29)) {
            try_move();
            // cout << my_stack.size() << endl;
            // for (int i = 1; i <= 29; i++) {
            //     for (int j = 0; j <= 29; j++) {
            //         if (my_stack.top().route[j] == i) {
            //             cout << " " << j+1;
            //         }
            //     }
            // }
            // cout << endl;
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

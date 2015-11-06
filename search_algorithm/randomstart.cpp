#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int queen[8];
bool is_found = false;
bool dead_end = false;
int neighbour[8];
unsigned seed = (unsigned)time(0);

void init_queen() {
    for(int i=0;i<8;i++){
        srand(seed++);
        int ran_num=rand() % 8;
        queen[i] = ran_num;
    }
    // cout << "init" << endl;
    // for (int i= 0; i < 8; i++) {
    //     cout << queen[i] << " ";
    // }
    // cout << endl;
}

int get_random() {
    srand(seed++);
    int res = rand() % 8;
    return res;
}

int h_value(int* a) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 8; ++j) {
            /* code to juge conflicts */
            if ((a[i]-a[j]) == (i-j)) {
                res++;
            }

            else if ((a[i]-a[j]) == (j-i)) {
                res++;
            }

            else if (a[i] == a[j]) {
                res++;
            }
        }
    }
    if (res == 0) is_found = true;
    return res;
}

void climb_hill() {

    for (int i = 0; i < 8; i++) {
        neighbour[i] = queen[i];
//        tmp[i] = queen[i];
    }

    bool visited[8][8];
    dead_end = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            visited[i][j] = false;
        }
    }

    while (h_value(neighbour) >= h_value(queen)) {
        int ran1 = get_random();
        int ran2 = get_random();

        neighbour[ran1] = ran2;
        visited[ran1][ran2] = true;

        dead_end = true;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (!visited[i][j]) dead_end = false;
            }
        }
        if (dead_end) break;

        if (h_value(neighbour) >= h_value(queen)) {
            neighbour[ran1] = queen[ran1];
        } else {
            for (int i = 0; i < 8; i++) {
                queen[i] = neighbour[i];
            }
            break;
        }
    }

    // for (int i= 0; i < 8; i++) {
    //     cout << queen[i] << " ";
    // }
    // cout <<h_value(queen) << endl;
}

int main() {
    int success = 0;
    long total = 1000;
    long num = total;
    while(total--) {
        is_found = false;
        dead_end = false;
        init_queen();
        while (!is_found) {
            if (dead_end) init_queen();
            climb_hill();
        }
        if (is_found) success++;
    }
    cout << "Total test num is " << num << ", " << success << " solutions are found" << endl;
}

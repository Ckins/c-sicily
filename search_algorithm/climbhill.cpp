#include <iostream>
#include <cstdlib>

using namespace std;

int queen[8];
bool is_found = false;
bool dead_end = false;
int neighbour[8];
unsigned seed = (unsigned)time(0);

void init_queen() {
    srand(seed++);
    for(int i=0;i<8;i++){
        int ran_num=rand() % 8;
        queen[i] = ran_num;
    }
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
    int tmp[8];

    // copy the cur state
    for (int i = 0; i < 8; i++) {
        tmp[i] = queen[i];
        neighbour[i] = queen[i];
    }


    for (int col = 0; col < 8; col++) {
        for (int row = 1; row < 8;row++) {
            tmp[col] = (tmp[col]+1) % 8;
            if (h_value(tmp) < h_value(neighbour)) {
                for (int k = 0; k < 8; k++) {
                    neighbour[k] = tmp[k];
                }
            }
        }
        tmp[col]++;
        tmp[col] %= 8;
    }

    dead_end = true;
    // the best neighbour assigned to queen
    for (int k = 0; k < 8; k++) {
        if (queen[k] != neighbour[k]) dead_end = false;
        queen[k] = neighbour[k];
    }
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
            if (dead_end) break;
            climb_hill();
        }
        if (is_found) success++;
    }
    cout << "Total test num is " << num << "," << success << " solutions are found" << endl;
}

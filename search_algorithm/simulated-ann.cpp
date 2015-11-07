#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int queen[8];
int neighbour[8];

int temp_step = 0;

bool is_found = false;
bool dead_end = false;
unsigned seed = (unsigned)time(0);

long double global_temp = 100000;

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

void getTemp() {
    global_temp *= 0.999;
}

bool should_accpet(double delta) {
    double ran = get_random()  / 7.0;
    double pro = exp(delta/global_temp);
    // cout << "por " << pro << " " << ran << endl;
    // cout << global_temp << " " << delta<< endl;
    return (ran < pro);
}

void climb_hill() {

    for (int i = 0; i < 8; i++) {
        neighbour[i] = queen[i];
//        tmp[i] = queen[i];
    }
    
    bool is_accept = false;

    while (!is_accept) {

        getTemp();
        int ran1 = get_random();
        int ran2 = get_random();

        neighbour[ran1] = ran2;

        double delta = h_value(queen)-h_value(neighbour);

        // if > 0 , it means better, samller , better
        if (delta > 0) {
            queen[ran1] = ran2;
            is_accept = true;
        } else {
            if (should_accpet(delta)) {
                queen[ran1] = ran2;
                is_accept = true;
            } else {
                neighbour[ran1] = queen[ran1];
            }
            
        }

        if (global_temp < 0.00001) {
            is_accept = true;
            dead_end = true;
        }
    }

    // for (int i= 0; i < 8; i++) {
    //     cout << queen[i] << " ";
    // }
    // cout <<h_value(queen) << "h_value"<< endl;
}

int main() {
    int success = 0;
    long total = 1000;

    long num = total;
    while(total--) {
        temp_step = 0;
        global_temp = 1000;
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

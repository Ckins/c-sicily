#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int getRan(void);

int main() {
    srand(time(NULL));
    int i =0;
    int j = 0;
    char ch = 'a';
    ofstream ofile;
    ofile.open("input");
    for (i = 0; i < 30000; i++) {
        int ranNum = getRan();
        ofile << char(ch+ranNum);
    }
    ofile.close();
    return 0;
}

int getRan() {
    int res;
    res = rand() % 26;
    return res;
}

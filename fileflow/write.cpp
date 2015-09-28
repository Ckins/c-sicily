#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int getRan(void);

int main() {

    int i =0;
    int a[100];
    for (i = 0; i < 100; i++) {
        a[i] = i;
    }
    char ch = 'a';
    ch++;
    cout << a[ch];
    ofstream ofile;
    ofile.open("input");
    ofile << "Test the file write" << endl;
    int ranNum = getRan();
    ofile << "The Random Num is :" << ranNum;
    ofile.close();
    return 0;
}

int getRan() {
    int res;
    srand(time(NULL));
    res = rand() % 10 +5;
    return res;
}

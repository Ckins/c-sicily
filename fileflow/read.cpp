#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int res[26];

int main() {

    int i = 0;
    for (i = 0; i < 26; i++) {
        res[i] = 0;
    }
    ifstream ifile("input");
    char ch;
    ifile.get(ch);
    while (!ifile.eof()) {
       ifile.get(ch);
       res[ch-'a']++;
    }
    ifile.close();
    for (i = 0; i < 26; i++) {
        ch = 'a'+char(i);
        cout << "The number of '" << ch << "' is : " << res[i] << endl;
    }
    return 0;
}

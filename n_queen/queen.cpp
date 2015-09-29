#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool chessboard[100][100];

class queen {

  public:
    queen(int r, int c) {
        row = r;
        col = c;
    }

    int row;
    int col;
};

vector<queen> queenStack;

bool isValid(queen* chess, int n);

void display(int n);

int main() {

    int n;
    cin >> n;

    int total = 0;
    int i = 0;
    int j = 0;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            chessboard[j][i] = false;
        }
    }

    queen* chess = new queen(0, 0);
    queenStack.insert(queenStack.begin(), *chess);

    bool isBacking = false;

    while (!queenStack.empty()) {
        int cur = queenStack.front().row;
        if (cur == n-1 && !isBacking) {
            display(n);
            total++;
        }

        if (!isBacking) {
            chess = new queen(cur+1, 0);
        } else {
            chess = new queen(cur, queenStack.front().col);
            queenStack.erase(queenStack.begin());
            chess->col += 1;
        }

        while (!isValid(chess, n)) {
            if (chess->col < n) {
                chess->col += 1;
            } else {
                break;
            }
        }
        if (chess->col >= n) {
            delete chess;
            isBacking = true;
        } else {
            queenStack.insert(queenStack.begin(), *chess);
            isBacking = false;
        }
    }

    cout << "There totally exists " << total << " solutions" << endl;
    return 0;
}

void display(int n) {
    int i = 0;
    int j = 0;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            chessboard[j][i] = false;
        }
    }
    cout << endl << endl << endl;
    vector<queen>::iterator it = queenStack.begin();
    for (; it != queenStack.end();it++) {
       chessboard[it->row][it->col] = true;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (chessboard[i][j]) {
                cout << "1" << " ";
            } else {
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
}

bool isValid(queen* chess, int n) {
    if (chess->col >= n) {
        return false;
    }
    vector<queen>::iterator it = queenStack.begin();
    for (;it != queenStack.end(); it++) {
        int col = (*it).col;
        int row = (*it).row;
        if (col == chess->col) {
            return false;
        }
        if (row == chess->row) {
            return false;
        }
        if (col - chess->col == row - chess->row) {
            return false;
        }
        if (col - chess->col == chess->row - row) {
            return false;
        }
    }
    return true;
}


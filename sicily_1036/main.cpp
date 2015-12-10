#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int getRightOrder(int* order, int key_length) {
    int select = 0;
    for (int i = 0 ; i < key_length; i++) {
        if (order[i] < order[select]) {
            select = i;
        }
    }
    order[select] = 999;
    return select;
}

int main() {
    string key;
    string crypto;

    while(cin >> key && key.compare(string("THEEND")) != 0) {
        cin >> crypto;
        int key_length = key.size();
        int text_length = crypto.size();
        int row_num = text_length / key_length;
        
        int order[11];
        char crypto_text[11][11];
        char origin_text[11][11];

        int row = 0;
        int col = 0;

        for (col = 0 ; col < key_length; col++) {
            for (row = 0; row < row_num; row++) {
                crypto_text[col][row] = crypto[col*row_num+row];
                //cout << crypto[col*row_num+row];
            }
        }

        for (int i = 0; i < key_length; i++) {
            order[i] = key[i]-'A';
        }

        for (int i = 0; i < key_length; i++) {
            int select = getRightOrder(order, key_length);
            for (int tmp_row = 0 ; tmp_row < row_num; tmp_row++) {
                origin_text[select][tmp_row] = crypto_text[i][tmp_row];
            }
        }

        for (row = 0; row < row_num; row++) {
            for (col = 0 ; col < key_length; col++) {
                cout << origin_text[col][row];
            }
        }
        cout << endl;
    }
}
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct moban {
    string a;
    string b;
    string op;
    int count;

    moban() {
        count = 0;
        op = "";
        a = "";
        b = "";
    }
    moban(string x = "", string y = "", int cou = 0, string curOp="") {
        a = x;
        b = y;
        count = cou;
        op = curOp;
    }
};

int m;
int head_count;
string tarA = "";
string tarB = "";
vector<moban> que;
vector<moban>::iterator head;

bool isvisited[8888][8888];

void rest_head() {
    head = que.begin();
    head += head_count;
}

bool cut_leaf(moban tmp) {
    int x = (tmp.a[0]-'0')*1000 + (tmp.a[1]-'0')*100 + (tmp.a[2]-'0')*10 + tmp.a[3]-'0';
    int y = (tmp.b[0]-'0')*1000 + (tmp.b[1]-'0')*100 + (tmp.b[2]-'0')*10 + tmp.b[3]-'0';
    if (!isvisited[x][y]) {
        isvisited[x][y] = true;
        return true;
    }
    return false;
}

void operations() {

    // bool a_not_repeat = true;
    // bool b_not_repeat = true;
    // bool c_not_repeat = true;

    int count = (*head).count;
    string op = (*head).op;
    string a = (*head).a;
    string b = (*head).b;
    // if (count > 0 && (*head).op[count-1] == 'A') {
    //     a_not_repeat = false;
    // }
    moban ban_a = moban(b+"", a+"", count+1, op+"A");

    // if (count > 2 && op[count-1] == 'B' && op[count-2] == 'B' && op[count-3] == 'B') {
    //     b_not_repeat = false;
    // }
    char t1 = a[3];
    char t2 = b[3];
    for (int i = 3; i > 0; i--)  {
        a[i] = a[i-1];
        b[i] = b[i-1];
    }
    a[0] = t1;
    b[0] = t2;
    moban ban_b = moban(a+"", b+"", count+1, op+"B");

    // if (count > 2 && op[count-1] == 'C' && op[count-2] == 'C' && op[count-3] == 'C') {
    //     c_not_repeat = false;
    // }
    a = (*head).a;
    b = (*head).b;
    char t = a[1];
    a[1] = b[1];
    b[1] = b[2];
    b[2] = a[2];
    a[2] = t;
    moban ban_c = (moban(a+"", b+"", count+1, op+"C"));

    if ( cut_leaf(ban_a)) que.push_back(ban_a);
    if ( cut_leaf(ban_b)) que.push_back(ban_b);
    if ( cut_leaf(ban_c)) que.push_back(ban_c);

    head_count++;
    rest_head();
}

bool isFound() {
    return ((*head).a == tarA && (*head).b == tarB);
}

bool isExceed() {
    return ((*head).count > m);
}

int main() {
    cin >> m;
    while (m != -1) {
        int i = 0;
        head_count = 0;
        que.clear();
        tarA = "";
        tarB = "";
        string tmp;
        for (i = 0; i < 4;i++) {
            cin >> tmp;
            tarA += tmp;
        }
        for (;i<8;i++) {
            cin >> tmp;
            tarB += tmp;
        }
        for (int i = 0; i < 8888; i++) {
            for (int j = 0; j < 8888; j++) {
                isvisited[i][j] = false;
            }
        }
        que.push_back(moban("1234", "8765", 0, ""));
        head = que.begin();
        while (!isFound()) {
            if (isExceed()) {
                cout << "-1" << endl;
                break;
            }
            operations();
        }
        if (isFound()) cout << (*head).count << " " << (*head).op << endl;
        cin >> m;
    }
    return 0;
}

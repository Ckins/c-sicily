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
string tarA = "";
string tarB = "";
queue<moban> que;

void operationA() {
    int count = que.front().count;
    string op = que.front().op;
    if (count > 0 && que.front().op[count-1] == 'A') {
        return;
    }
    que.push(moban(que.front().b,que.front().a, count+1, op+"A"));
}

void operationB() {

    int count = que.front().count;
    string op = que.front().op;
    if (count > 2 && op[count-1] == 'B' && op[count-2] == 'B' && op[count-3] == 'B') {
        return;
    }
    string a = que.front().a;
    string b = que.front().b;
    char t1 = a[3];
    char t2 = b[3];
    for (int i = 3; i > 0; i--)  {
        a[i] = a[i-1];
        b[i] = b[i-1];
    }
    a[0] = t1;
    b[0] = t2;
    que.push(moban(a, b, count+1, op+"B"));
}

void operationC() {

    int count = que.front().count;
    string op = que.front().op;
    if (count > 2 && op[count-1] == 'C' && op[count-2] == 'C' && op[count-3] == 'C') {
        return;
    }

    string a = que.front().a;
    string b = que.front().b;
    char t = a[1];
    a[1] = b[1];
    b[1] = b[2];
    b[2] = a[2];
    a[2] = t;
    que.push(moban(a, b, count+1, op+"C")); 
}

bool isFound() {
    return (que.front().a == tarA && que.front().b == tarB);
}

bool isExceed() {
    return (que.front().count > m);
}

void clear() {
    if (!que.empty()) {
        que.pop();
    }
}

int main() {
    cin >> m;
    while (m != -1) {
        int i = 0;
        clear();
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
        que.push(moban("1234", "8765", 0, ""));
        while (!isFound()) {
            if (isExceed()) {
                cout << "-1" << endl;
                break;
            }
            cout << que.front().a << endl;
            cout << que.front().b << endl << endl;
            operationA();
            operationB();
            operationC();
            que.pop();
        }
        if (isFound()) cout << que.front().count << " " << que.front().op << endl;
        cin >> m;
    }
}
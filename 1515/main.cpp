#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

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
int factor[] = {1,1,2,6,24,120,720,5040};
string tarA = "";
string tarB = "";
queue<moban> que;
bool is_visited[40320];

bool cut_leaf(moban tmp) {
    int x[] = {(tmp.a[0]-'0'), (tmp.a[1]-'0'), (tmp.a[2]-'0'), (tmp.a[3]-'0'),
               (tmp.b[0]-'0'), (tmp.b[1]-'0'), (tmp.b[2]-'0'), tmp.b[3]-'0'};

    int cantor[8] = {0};

    int i, j;
    unsigned int result = 0;
    for (i = 0; i < 8; i++) {
        int tmp = x[i]-1;
        for (j = 0; j < i;j++) {
            if (x[j] < x[i]) {
                tmp--;
            }
        }
        cantor[i] = tmp;
    }
    for (i = 0; i < 8; i++) {
        result += cantor[i]*factor[7-i];
    }
    if (!is_visited[result]) {
        is_visited[result] = true;
        return true;
    }
    return false;
}

void moveA() {
    int count = que.front().count;
    string op = que.front().op;
    string a = que.front().a;
    string b = que.front().b;
    for (int i = 0; i < 2; i++) {
        char t = a[i];
        char t2 = b[i];
        a[i] = a[i+2];
        b[i] = b[i+2];
        a[i+2] = t;
        b[i+2] = t2;
    }
    moban tmp = moban(a, b, count+1, op+"A");
    if (cut_leaf(tmp)) que.push(tmp);
}

void moveB() {

    int count = que.front().count;
    string op = que.front().op;
    string a = que.front().a;
    string b = que.front().b;
    char t1 = a[0];
    char t2 = b[0];
    for (int i = 0; i < 3; i++)  {
        a[i] = a[i+1];
        b[i] = b[i+1];
    }
    a[3] = t1;
    b[3] = t2;
    moban tmp = moban(a, b, count+1, op+"B");
    if (cut_leaf(tmp)) que.push(tmp);
}

void moveC() {

    int count = que.front().count;
    string op = que.front().op;
    string a = que.front().a;
    string b = que.front().b;
    char t = a[1];
    a[1] = a[2];
    a[2] = b[2];
    b[2] = b[1];
    b[1] = t;
    moban tmp = moban(a, b, count+1, op+"C");
    if (cut_leaf(tmp)) que.push(tmp);
}

bool isFound() {
    return (que.front().a == tarA && que.front().b == tarB);
}

bool isExceed() {
    return (que.front().count > m);
}

void clear() {
    while (que.size() != 0) {
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
        for (int i = 0; i < 40320; i++) {
            is_visited[i] = false;
        }
        que.push(moban("1234", "5678", 0, ""));
        while (!isFound()) {
            if (isExceed()) {
                cout << "-1" << endl;
                break;
            }
            moveA();
            moveB();
            moveC();
            que.pop();
        }
        if (isFound() && !que.empty()) cout << que.front().count << " " << que.front().op << endl;
        cin >> m;
    }
}

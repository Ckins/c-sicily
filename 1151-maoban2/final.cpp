#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

/* @param op 记录操作序列
 * @param count 记录操作步数
 * @param a 记录魔板状态
 * @param b  
 *
*/
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

//使用康拓展开将阶乘数量的节点状态压缩映射为十进制数表示，节省bool数组的空间。
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

//魔板操作A
void moveA() {
    int count = que.front().count;
    string op = que.front().op;
    string a = que.front().b;
    string b = que.front().a;
    moban tmp = moban(a, b, count+1, op+"A");
    if (cut_leaf(tmp)) que.push(tmp);
}


//魔板操作B
void moveB() {

    int count = que.front().count;
    string op = que.front().op;
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
    moban tmp = moban(a, b, count+1, op+"B");
    if (cut_leaf(tmp)) que.push(tmp);
}

//魔板操作C
void moveC() {

    int count = que.front().count;
    string op = que.front().op;
    string a = que.front().a;
    string b = que.front().b;
    char t = a[1];
    a[1] = b[1];
    b[1] = b[2];
    b[2] = a[2];
    a[2] = t;
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

void init() {
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
    memset(is_visited, 0, 40320);
}

int main() {
    cin >> m;
    while (m != -1) {
        
        init();
        que.push(moban("1234", "8765", 0, ""));
        //三叉数的状态遍历。直到找到目标操作序列或者超出数目范围。
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

#define POS_NUM 64
#define X_DOWN 0
#define X_UP 8
#define Y_DOWN 0
#define Y_UP 8

#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

bool chess_board[X_UP][Y_UP];
bool reach_end;
int travel_path[POS_NUM];

struct position {
    int x;
    int y;
    int next;

    position(int c_x = 0, int c_y = 0, int n_num = 0) : x(c_x), y(c_y), next(n_num) {}

    void set(position* p1, position* p2) {
        p1->x = p2->x;
        p1->y = p2->y;
        p1->next = p2->next;
    }

    //重载＝符号
    position& operator=(const position& p) {
        set(this, (position*)&p);
    }

    //复制构造函数
    position(const position& p) {
        this->x = p.x;
        this->y = p.y;
        this->next = p.next;
    }
};

//马走日字的八个方向
const position direction[8] = {
    position(-2, -1), position(-1, -2),
    position(-1, 2), position(-2, 1),
    position(1, -2), position(2, -1),
    position(2, 1), position(1, 2)
};

//判断某个位置是否合法
bool isValid(const position& pos) {
  return pos.x >= X_DOWN && pos.x < X_UP && pos.y >= Y_DOWN && pos.y < Y_UP;
}

//选择排序，由大到小选出后继可行步骤
void select_sort(position* a, int avaliable) {
    for (int i = 0 ; i < avaliable; i++) {
        int max = i;
        for (int j = i+1; j < avaliable;j++) {
            if (a[j].next > a[max].next) {
                max = j;
            }
        }
        position tmp = a[max];
        a[max] = a[i];
        a[i] = tmp;
    }
}

//深度优先搜索，使用函数栈回溯
void try_move(position last_pos, int steps) {

    int x = last_pos.x;
    int y = last_pos.y;

    //没有找到路线，继续往下找
    //用于找到路径后，快速释放函数调用的空间
    if (!reach_end) {

        //如果步数到达最大NUM，则表明找到了，打印路径
        if (steps >= POS_NUM-1) {
            reach_end = true;
            printf("%d", travel_path[0]);
            for (int i = 1; i < POS_NUM;i++) {
                printf(" %d", travel_path[i]);
            }
            printf("\n");
        } else {
            // 否则需要往下找
            position p[8];
            int avl = 0;
            
            // 遍历８个可能的行走方向
            for (int i = 0; i < 8; i++) {
                // 第一层可行的子节点
                position outter(x+direction[i].x, y+direction[i].y);
                if (isValid(outter) && !chess_board[outter.x][outter.y]) {
                    p[avl] = outter;

                    // 第二层可行的子节点
                    for (int j = 0; j < 8; j++) {
                        position inner(outter.x + direction[j].x, outter.y + direction[j].y);
                        if (isValid(inner)) {
                            //要多遍历一层,记录后继可行节点数
                            if (!chess_board[inner.x][inner.y]) p[avl].next++;
                        }
                    }
                    //记录当前方向
                    avl++;
                }
            }
            //对可行的下一步进行排序，确定优先级
            select_sort(p, avl);

            //后继节点少的位置优先采用
            while(avl--) {

                //尝试下一步
                chess_board[p[avl].x][p[avl].y] = true;
                travel_path[steps + 1] = p[avl].x * X_UP + p[avl].y + 1;
                try_move(p[avl], steps + 1);

                // 尝试失败后，将棋盘标记还原
                chess_board[p[avl].x][p[avl].y] = false;
            }
        }
    }
}

//初始化棋盘和路径
position init(int start) {
    travel_path[0] = start;
    reach_end = false;
    memset(chess_board, false, sizeof(chess_board));
    int x = (start-1) / X_UP, y = (start-1) % Y_UP;    
    chess_board[x][y] = true;
    position res(x, y);
    return res;   
}

int main() {
    int start;
    while (scanf("%d", &start) && start!=-1) {
        //获取输入，进行深搜
        try_move(init(start), 0);
    }
    return 0;
}

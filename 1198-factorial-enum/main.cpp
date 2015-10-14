#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int total, num;
    cin >> total;
    while (total--) {
        bool used[10];
        for (int i = 0; i < 10; i++) {
            used[i] = false;
        }
        cin >> num;
        vector<string> vec;
        for (int i = 0; i < num; i++) {
            string tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        vector<string>::iterator it;
        vector<string>::iterator best = vec.begin();
        string res = "";
        while (num--) {
            best = vec.begin();
            for(it = vec.begin(); it != vec.end(); it++) {
                //这样的比较就可以避免c，ca这种情况的出现判断！输出的是cac，而不是cca！
                if ((*it + *best) < *best+*it) {
                    best = it;
                }
            }
            res += *best;
            *best="{";
        }
        cout << res << endl;
    }
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string val[100];
string res[200];
int min_num;
int res_choice;
int test_num;

int getDiffNum(string sub_str) {
    int result = 0;
    int size = sub_str.size()-1;
    for (int i = 0; i < test_num; ++i) {
        /* code */
        string rank = val[i];
        //cout << rank << " " << sub_str << " ";
        for (int pos = 0; pos < size; pos++) {
            int pos_in_rank = 0;
            for (int j = 0; j < rank.size();j++) {
                if (sub_str[pos] == rank[j]) {
                    pos_in_rank = j;
                    break;
                }
            }

            //cout << "pos: " << pos_in_rank;
            //compare diff
            for (int out = pos+1; out < size+1; out++) {
                bool isBehind = false;
                for (int k = pos_in_rank+1; k < rank.size(); ++k)
                {
                    /* code */
                    if (sub_str[out] == rank[k]) {
                        isBehind = true;
                        break;
                    }
                }
                if (!isBehind) result++;
            }
            //cout << " res: " << result << endl;
        }
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    /* code */

    string str = string("ABCDE");
    res[0] = str;
    int count = 1;
    while(next_permutation(str.begin(), str.end())) {
    
        res[count++] = str;
    }

    while (cin >> test_num && test_num != 0) {

        for (int i = 0; i < test_num; ++i)
        {
            /* code */
            cin >> val[i];
        }

        min_num = getDiffNum(string("ABCDE"));
        for (int i = 1; i < count; i++) {
            //cout << res[i] << endl;
            int tmp = getDiffNum(res[i]);
            //cout << tmp << endl;
            if (tmp < min_num) {
                min_num = tmp;
                res_choice = i;
            }
        }

        cout << res[res_choice] << " is the median ranking with value " << min_num << "." << endl;
        
    }

    return 0;
}
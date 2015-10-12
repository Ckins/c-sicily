#include <iostream>
#include <vector> 
#include <string>

using namespace std;

bool isMatch(string a, string b) {
    int i = 0;
    if (a.length() != b.length()) {
        return false;
    }
    for(; i < a.length();i++) {
        if ((a[i] == 'A' && b[i] == 'T')) {
            continue;
        } else if (a[i] == 'T' && b[i] == 'A') {
            continue;
        } else if (a[i] == 'C' && b[i] == 'G') {
            continue;
        } else if (a[i] == 'G' && b[i] == 'C') {
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<string> dna;
        int num;
        int res = 0;
        cin >> num;
        for (int j = 0; j < num; j++) {
            string str;
            cin >> str;
            dna.push_back(str);
        }
        std::vector<string>::iterator it = dna.begin();
        for (; it != dna.end();it++) {
            vector<string>::iterator inner;
            for ( inner = it+1;inner != dna.end();inner++) {
                if (*inner == "used") {
                    continue;
                }
                if (isMatch(*it, *inner)) {
                    *it = "used";
                    *inner = "used";
                    res++;
                    break;
                }
                
            }
            
        }
        dna.clear();
        cout << res << endl;
    }    
}

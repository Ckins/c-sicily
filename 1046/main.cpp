#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class seq {
  public:
    seq(int l, int e, double a) {
        last = l;
        end = e;
        ave = a;
    }

    int getLast() const {
        return last;
    }

    int getEnd() const {
        return end;
    }
    double getAve() const{
        return ave;
    }

    bool operator>(const seq &b) const{
        if (ave > b.getAve()) {
            return true;
        }
        if (ave == b.getAve() && last>b.getLast()) {
            return true;
        }
        if (ave == b.getAve() && last == b.getLast() && end < b.getEnd()) {
            return true;
        }
        return false;
    }

  private:
    int last;
    int end;
    double ave;
};

int main() {
    int totalNum = 0;
    cin >> totalNum;
    for (int now = 1; now <= totalNum; now++) {
        int n, m, q;
        std::vector<seq> v;
        int times[500];
        cin >> n >> q >> m;
        for (int i = 0; i < n; i++) {
            cin >> times[i];
        }
        //int bestNum = 0;
        for (int out = m; out <= n; out++) {
            for (int inner = 1; inner <= n-out+1; inner++) {
                double res = 0.0;
                for (int k = inner; k < inner+out; k++) {
                    res += times[k-1];
                }
                res /= out;
                seq tmp(out, inner+out-1, res);
                v.push_back(tmp);
            }
        }
        cout << "Result for run " << now << ":" << endl; 
        for (int i = 0; i < q; i++) {
            if (v.empty()) {
                break;
            }
            vector<seq>::iterator it = v.begin();
            vector<seq>::iterator best = v.begin();
            for (; it != v.end();it++) {
                if (*it > *best) {
                    best = it;
                }
            }
            cout << (*best).getEnd()-(*best).getLast()+1 << "-" << (*best).getEnd() << endl;
            v.erase(best);
        }
    }
}

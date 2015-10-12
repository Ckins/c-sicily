#include <iostream>
#include <utility>

using namespace std;

class seq {
  public:
    seq(int b, int e, double a) {
        begin = b;
        end = e;
        ave = a;
    }

    int getBegin() const {
        return begin;
    }

    int getEnd() const {
        return end;
    }
    double getAve() const{
        return ave;
    }

    bool operator>(const seq &b) const{

    }

  private:
    int begin;
    int end;
    double ave;
};

int main() {

}

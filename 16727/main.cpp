#include <iostream>

using namespace std;

int main()

{

      cout<<"Goodbye world"<<endl;

      return 0;

}

//your code will be here
class Hello {
    ostream& out_;
public:
    Hello(ostream& out) : out_(out) {
        cout << "Hello World" << endl;
        cout.setstate(std::ios_base::failbit);
    }

    ~Hello() {
        cout.clear();
    }
};

Hello myout(std::cout);

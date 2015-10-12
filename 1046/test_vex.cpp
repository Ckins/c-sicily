#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

std::vector<int>::iterator it1;
std::vector<int>::iterator it2;
std::vector<int>::iterator it3;

void init() {
    vec.clear();
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    it1 = vec.begin();
    it2 = vec.begin();
    it3 = vec.begin();

    for (int i = 0; i < 3; i++) {
        it2++;
    }

    for (int i = 0; i < 5; i++) {
        it3++;
    }
}

void display() {
    cout << "It1: " << *it1 << endl;
    cout << "It2: " << *it2 << endl;
    cout << "It3: " << *it3 << endl << endl;    
}

int main() {

    init();
    display();

    cout << endl << "test erase :" << endl;
    it1 = vec.erase(it1);
    display();

    init();
    cout << endl << "test insert :" << endl;
    vec.insert(it2, 88);
    display();

}

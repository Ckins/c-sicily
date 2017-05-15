#include<iostream>
#include<cstdio>

using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) { } 
};

Point operator+ (const Point& A, const Point& B) {
	return Point(A.x+B.x, A.y+B.y);
}

ostream& operator<< (ostream& out, Point& P) {
	out << "(" << P.x << "," << P.y << ")";
	return out;
}

int main() {
	Point a, b(1,2);
	a.x = 3;
	cout << a << "\n";
	return 0;
}
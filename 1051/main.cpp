#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int re;
    double dia, t;
    int run = 1;
    cin >> dia >> re >> t;
    while (re != 0) {
        double length_inch = re * dia * 3.1415927;
        double length_mile = length_inch/12/5280;
        double t_hour = t/3600;
        double speed = length_mile/t_hour;
        cout << "Trip #" << run << ": " << setiosflags(ios::fixed) << setprecision(2) << length_mile << " " << speed << endl;
        run++;
        cin >> dia >> re >> t;
    }
}
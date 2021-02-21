#include <iostream>
using namespace std;

double estimate_pi() {
    srand(time(0));
    int circle_points = 0;
    int square_points = 0;

    for (int i=0; i<1000*1000; i++) {
        double x = double(rand() % 1001)/1000;
        double y = double(rand() % 1001)/1000;

        if (x*x + y*y <= 1) {
            circle_points++;
        }
        square_points++;
    }
    double pi = double(4 * circle_points)/square_points;
    return pi;
}

int main() {
    cout << estimate_pi() << endl;
}
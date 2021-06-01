/*
This problem was asked by Microsoft.

Given a clock time in hh:mm format, determine, to the nearest degree, the angle between the hour and the minute hands.

Bonus: When, during the course of a day, will the angle be zero?
*/

#include <iostream>
using namespace std;

double angleClock(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    double hourAngle = (hour % 12 + (double) (minute / 60.0)) * 30.0;
    double minuteAngle = minute * 6;

    double res = abs(hourAngle - minuteAngle);

    return res > 180 ? 360 - res : res;
}

int main() {
    cout << angleClock("12:30") << endl;
    cout << angleClock("03:30") << endl;
}

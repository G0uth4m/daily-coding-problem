/*
This question was asked by Riot Games.

Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following operations:

    record(timestamp): records a hit that happened at timestamp
    total(): returns the total number of hits recorded
    range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

Follow-up: What if our system has limited memory?
*/

#include <iostream>
#include <set>
using namespace std;

class HitCounter {
private:
    set<int> timestamps;
public:

    // O(log n)
    void record(int timestamp) {
        timestamps.insert(timestamp);
    }

    // O(1)
    int total() {
        return timestamps.size();
    }

    // O(n)
    int range(int lower, int higher) {
        set<int>::iterator low = timestamps.lower_bound(lower);
        set<int>::iterator high = timestamps.lower_bound(higher);
        if (high == timestamps.end() || *high != higher) {
            return distance(low, high);
        } 
        return distance(low, high) + 1;
    }
};

int main() {
    HitCounter hitCounter;
    hitCounter.record(1);
    hitCounter.record(10);
    hitCounter.record(20);
    hitCounter.record(30);
    hitCounter.record(40);

    cout << hitCounter.total() << endl;
    cout << hitCounter.range(5, 30) << endl;
    cout << hitCounter.range(10, 30) << endl;
    cout << hitCounter.range(10, 35) << endl;
    cout << hitCounter.range(10, 45) << endl;
}
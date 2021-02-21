#include <iostream>
#include <vector>
using namespace std;

class Log {
private:
    vector<int>* circular_buffer;
    size_t capacity;
    int curr_idx;

public:
    Log(size_t capacity) {
        circular_buffer = new vector<int>(capacity);
        this->capacity = capacity;
        curr_idx = 0;
    }

    void record(int order_id) {
        circular_buffer->at(curr_idx) = order_id;
        curr_idx = (curr_idx + 1) % capacity;
    }

    int get_last(int i) {
        return circular_buffer->at((capacity + curr_idx - i) % capacity);
    }
};

int main() {
    Log log(5);
    log.record(1);
    log.record(2);
    log.record(3);
    log.record(4);
    log.record(5);

    cout << log.get_last(1) << endl;
    cout << log.get_last(2) << endl;

    log.record(6);

    cout << log.get_last(1) << endl;
    cout << log.get_last(2) << endl;
}
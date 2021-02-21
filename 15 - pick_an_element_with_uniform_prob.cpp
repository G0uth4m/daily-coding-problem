#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int count = 0;

int pick_random_element(int num) {
    srand(time(0));
    count++;
    if (count == 1) {
        res = num;
    } else {
        int r = rand() % count;
        if (r == count - 1) {
            res = num;
        }
    }
    return res;
}

int main() {
    vector<int> stream = {0, 1, 2, 3, 4, 5, 6, 7};

    for(int i=0; i<stream.size(); i++) {
        cout << pick_random_element(stream[i]) << " ";
    }
    cout << endl;
}
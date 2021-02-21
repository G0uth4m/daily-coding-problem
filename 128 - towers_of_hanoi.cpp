/*
The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.

All the disks start off on the first rod in a stack. 
They are ordered by size, with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

    You can only move one disk at a time.
    A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
    You cannot place a larger disk on top of a smaller disk.

Write a function that prints out all the steps necessary to complete the Tower of Hanoi. 
You should assume that the rods are numbered, with the first rod being 1, 
the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:

    Move 1 to 3
    Move 1 to 2
    Move 3 to 2
    Move 1 to 3
    Move 2 to 1
    Move 2 to 3
    Move 1 to 3

*/

#include <iostream>
#include <vector>
using namespace std;

class Tower {
private:
    vector<size_t> disks;

    void _move(size_t n, Tower* buffer, Tower* destination) {
        if (n > 0) {
            this->_move(n - 1, destination, buffer);
            this->moveTopTo(destination);
            buffer->_move(n - 1, this, destination);
        }
    }
    int id;

public:
    Tower(int id) {
        this->id = id;
    }

    int getId() {
        return this->id;
    }

    void addTop(size_t disk) {
        if (!disks.empty() && disk > this->top()) {
            throw "Can't place disk on a smaller disk";
        }
        disks.push_back(disk);
    }

    size_t removeTop() {
        if (disks.empty()) {
            throw "Empty tower";
        }
        disks.pop_back();
    }

    void moveTopTo(Tower* t) {
        cout << "Move " << this->top() << " to " << t->getId() << endl;
        t->addTop(top());
        this->removeTop();
    }

    size_t top() {
        return disks.back();
    }

    void move(Tower* buffer, Tower* destination) {
        this->_move(disks.size(), buffer, destination);
    }
};

int main() {
    Tower* src = new Tower(1);
    src->addTop(3);
    src->addTop(2);
    src->addTop(1);

    Tower* buffer = new Tower(2);
    Tower* destination = new Tower(3);

    src->move(buffer, destination);
}
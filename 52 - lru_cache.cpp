/*
This problem was asked by Google.

Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, 
and contain the following methods:

> set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, 
  then it should also remove the least recently used item.
> get(key): gets the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

struct ValueWithTimeStamp {
    int timestamp;
    int value;
};

class LRUCache {
private:
    unordered_map<int, ValueWithTimeStamp> cache;
    size_t capacity;
    size_t timestamp;

public:
    LRUCache(size_t capacity) {
        cache.reserve(capacity);
        this->capacity = capacity;
        timestamp = 0;
    }

    void set(int key, int value) {
        if (cache.size() == capacity && cache.find(key) == cache.end()) {
            int lru = INT32_MAX;
            for (auto i : cache) {
                lru = min(lru, i.first);
            }
            cache.erase(lru);
        }
        cache[key] = {++timestamp, value};
    }

    int get(int key) {
        cache[key].timestamp = ++timestamp;
        return cache[key].value;
    }
};

class LRUCache2 {
private:
    unordered_map<int, int> cache;
    list<int> q;
    size_t capacity;
    
public:
    LRUCache2(size_t capacity) {
        cache.reserve(capacity);
        this->capacity = capacity;
    }

    void set(int key, int value) {
        if (cache.size() == capacity && cache.find(key) == cache.end()) {
            cache.erase(q.front());
            q.pop_front();
        } else if (cache.find(key) != cache.end()) {
            q.remove(key);
            q.push_back(key);
        } else {
            q.push_back(key);
        }
        cache[key] = value;
    }

    int get(int key) {
        q.remove(key);
        q.push_back(key);
        return cache[key];
    }
};

struct ValueWithIter {
    int value;
    list<int>::iterator iter;
};

// optimal
class LRUCache3 {
private:
    unordered_map<int, ValueWithIter> cache;
    list<int> q;
    size_t capacity;

public:
    LRUCache3(size_t capacity) {
        cache.reserve(capacity);
        this->capacity = capacity;
    }

    void set(int key, int value) {
        if (cache.size() == capacity) {
            if (cache.find(key) != cache.end()) {
                q.erase(cache[key].iter);
                q.push_front(key);
                cache[key] = {value, q.begin()};
            } else {
                cache.erase(q.back());
                q.pop_back();
                q.push_front(key);
                cache[key] = {value, q.begin()};
            }
        } else {
            if (cache.find(key) != cache.end()) {
                q.erase(cache[key].iter);
                q.push_front(key);
                cache[key] = {value, q.begin()};
            } else {
                q.push_front(key);
                cache[key] = {value, q.begin()};
            }
        }
    }

    int get(int key) {
        q.erase(cache[key].iter);
        q.push_front(key);
        cache[key].iter = q.begin();
        return cache[key].value;
    }
};
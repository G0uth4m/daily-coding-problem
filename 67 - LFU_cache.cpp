/*
This problem was asked by Google.

Implement an LFU (Least Frequently Used) cache. It should be able to be initialized with a cache size n, 
and contain the following methods:

> set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, 
  then it should also remove the least frequently used item. 
  If there is a tie, then the least recently used key should be removed.
> get(key): gets the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct ValWithUsage {
    int val;
    int usage;
    int timestamp;
};

class LFUCache {
private:
    unordered_map<int, ValWithUsage> cache;
    size_t capacity;
    int timestamp;

public:
    LFUCache(size_t capacity) {
        cache.reserve(capacity);
        this->capacity = capacity;
        timestamp = 0;
    }

    void set(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache.at(key).usage++;
            cache.at(key).val = value;
        } else {
            if (cache.size() == capacity) {
                int lfu_key = INT32_MAX;
                int lfu = INT32_MAX;
                for (auto i : cache) {
                    if (i.second.usage < lfu) {
                        lfu = i.second.usage;
                        lfu_key = i.first;
                    } else if (i.second.usage == lfu) {
                        if (i.second.timestamp < cache.at(lfu_key).timestamp) {
                            lfu_key = i.first;
                        }
                    }
                }
                cache.erase(lfu_key);
            }
            cache[key] = {value, 1};
        }
        cache.at(key).timestamp = ++timestamp;
    }

    int get(int key) {
        cache.at(key).usage++;
        cache.at(key).timestamp = ++timestamp;
        return cache.at(key).val;
    }
};
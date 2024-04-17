#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = _cache.find(key);
        if (it == _cache.end()) return -1;
        _lru.splice(_lru.begin(), _lru, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = _cache.find(key);
        if (it != _cache.end()) {
            it->second->second = value;
            _lru.splice(_lru.begin(), _lru, it->second);
            return;
        }

        if (_cache.size() >= _capacity) {
            int lruKey = _lru.back().first;
            _cache.erase(lruKey);
            _lru.pop_back();
        }
        _lru.emplace_front(key, value);
        _cache[key] = _lru.begin();
    }

private:
    int _capacity;
    list<pair<int, int>> _lru;
    unordered_map<int, list<pair<int, int>>::iterator> _cache;
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; 
    cache.put(3, 3); 
    cout << cache.get(2) << endl; 
    cache.put(4, 4); 
    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl; 

    return 0;
}

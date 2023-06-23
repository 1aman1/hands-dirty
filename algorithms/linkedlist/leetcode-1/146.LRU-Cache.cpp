#include <iostream>
#include <list>
#include <unordered_map>

struct kvNode
{
    int key;
    int value;

    kvNode(int Key, int Value) : key(Key), value(Value) {}
};

class LRUCache
{
    std::list<kvNode> list; // hold K-V pairs
    std::unordered_map<int, std::list<kvNode>::iterator> cache;
    size_t capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int
    get(int key);

    void
    put(int key, int value);
};

void LRUCache::put(int key, int value)
{
    if (cache.count(key))
    {
        const auto &cacheItrToKey = cache.at(key);
        list.splice(begin(list), list, cacheItrToKey);
        cacheItrToKey->value = value;

        return;
    }

    if (capacity == list.size())
    {
        const auto &evictNode = list.back();
        cache.erase(evictNode.key);
        list.pop_back();
    }

    list.emplace_front(key, value);
    cache[key] = begin(list);
}

int LRUCache::get(int key)
{
    if (!cache.count(key))
    {
        return -1;
    }

    const auto &cacheItrToKey = cache.at(key);
    list.splice(begin(list), list, cacheItrToKey);

    return list.front().value;
}

int main()
{
    LRUCache *lRUCache = new LRUCache(2);

    lRUCache->put(1, 100);

    lRUCache->put(2, 100);

    lRUCache->put(2, 300);

    lRUCache->put(4, 100);

    std::cout << lRUCache->get(1) << "\n";

    std::cout << lRUCache->get(2) << "\n";

    return 0;
}
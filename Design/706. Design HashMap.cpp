using p = pair<int, int>;

class MyHashMap {
private:
    vector<list<p>> buckets;
    int size;

public:
    MyHashMap() {
        size = 10000;
        buckets.resize(size); 
    }

    void put(int key, int value) {
        int bucketNo = key % size;
        for (auto &it : buckets[bucketNo]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        buckets[bucketNo].push_back({key, value});
    }

    int get(int key) {
        int bucketNo = key % size;
        for (auto &it : buckets[bucketNo]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int bucketNo = key % size;
        auto &chain = buckets[bucketNo];
        for (auto it = chain.begin(); it != chain.end(); ) {
            if (it->first == key) {
                it = chain.erase(it);
            } else {
                ++it;
            }
        }
    }
};

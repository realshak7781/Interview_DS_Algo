class MyHashSet {
private:
vector<list<int>> buckets;  
int size;  
public:
    MyHashSet() {
        size=10000; 
        buckets.resize(size);
    }
    
    void add(int key) {
        int bucketCnt=key%size;

        for(int k:buckets[bucketCnt]){
            if(k==key) return;
        }
        buckets[bucketCnt].push_back(key);
    }
    
    void remove(int key) {
        int bucketCnt=key%size;
        auto &bucket=buckets[bucketCnt];
        for(auto it=bucket.begin();it!=bucket.end();){
            if(*it==key){
                it=bucket.erase(it);
                return;
            }
            ++it;
        }
    }
    
    bool contains(int key) {
         int bucketCnt=key%size;

        for(int k:buckets[bucketCnt]){
            if(k==key) return true;
        }
        
        return false;
    }
};


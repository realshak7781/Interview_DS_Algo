class RandomizedSet {
private:
unordered_map<int,int> mp;
vector<int> arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)==false){
            mp[val]=arr.size();
            arr.push_back(val);
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)==false) return false;

        int idx=mp[val];
        arr[idx]=arr[arr.size()-1];
        arr.pop_back();
        if(idx<arr.size())mp[arr[idx]]=idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx=rand()%arr.size();

        return arr[idx];
    }
};


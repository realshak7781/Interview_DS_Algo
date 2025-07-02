// Better:

struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

class AllOne {
private:
    unordered_map<string, int> mp;
    multiset<pair<string, int>, cmp> ms;

public:
    AllOne() {}

    void inc(string key) {
        if (mp.count(key)) {
            int oldCnt = mp[key];
            ms.erase(ms.find({key, oldCnt}));
            mp[key]++;
            ms.insert({key, mp[key]});
        } else {
            mp[key] = 1;
            ms.insert({key, 1});
        }
    }

    void dec(string key) {
        if (!mp.count(key)) return;

        int oldCnt = mp[key];
        ms.erase(ms.find({key, oldCnt}));

        mp[key]--;
        if (mp[key] == 0) {
            mp.erase(key);
        } else {
            ms.insert({key, mp[key]});
        }
    }

    string getMaxKey() {
        if (ms.empty()) return "";
        return ms.rbegin()->first;
    }

    string getMinKey() {
        if (ms.empty()) return "";
        return ms.begin()->first;
    }
};



//BRUTE FORCE : O(N^2)
class AllOne {
private:
unordered_map<string,int> mp; 
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0) mp.erase(key);
    }
    
    string getMaxKey() {
        string maxi="";
        int maxCnt=-1;
        for(auto &it:mp){
            if(it.second>maxCnt){
                maxCnt=it.second;
                maxi=it.first;
            }
        }

        return maxi;
    }
    
    string getMinKey() {
        string mini="";
        int minCount=1e9;

        for(auto &it:mp){
            if(it.second<minCount){
                minCount=it.second;
                mini=it.first;
            }
        }

        return mini;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */




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

class Solution {    
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>> mp;
        mp['N']={0,1};
        mp['S']={0,-1};
        mp['E']={1,0};
        mp['W']={-1,0};

        multiset<pair<int,int>> ms;
        pair<int,int> cur={0,0};
        ms.insert(cur);

        for(char c:path){
            pair<int,int> dir=mp[c];
            pair<int,int> newC;
            newC.first=cur.first+dir.first;
            newC.second=cur.second+dir.second;

            auto it=ms.find(newC);

            if(it!=ms.end()) return true;

            ms.insert(newC);
            cur=newC;
        }

        return false;
    }
};

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,bool> visMap;

        for(auto &it:paths){
            string src=it[0];
            string dest=it[1];

            visMap[src]=true;
            if(!visMap.count(dest))visMap[dest]=false;
            
        }


        string stop="";
        for(auto &it:visMap){
            if(it.second==false){
                stop=it.first;
                break;
            }
        }

        return stop;
    }
};

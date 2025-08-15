class Solution {
public:
    bool buddyStrings(string s, string goal) {
        unordered_map<char,int> freq;
        
        if(s.length()!=goal.length()) return false;
            
        for(int i=0;i<s.length();i++){
                freq[s[i]]++;
        }
            
        if(s==goal){
            for(auto &it:freq){
                    if(it.second>=2) return true;
            }
           
                return false;
        }
            
        int diffPos=0;
            
        for(int i=0;i<s.length();i++){
                if(s[i]!=goal[i]) diffPos++;
        }
            
            if(diffPos>2) return false;
            
        for(int i=0;i<goal.length();i++){
                freq[goal[i]]--;
                
                if(freq[goal[i]]==0){
                        freq.erase(goal[i]);
                }
        }
            
            return freq.size()==0;
    }
};

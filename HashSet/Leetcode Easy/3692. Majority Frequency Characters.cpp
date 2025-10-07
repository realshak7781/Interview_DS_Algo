class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        unordered_map<int,vector<char>> mp;

        for(char c:s){
            freq[c]++;
        }

        for(auto it:freq){
            mp[it.second].push_back(it.first);
        }

        string res="";
        int maxK=-1;
        int maxSize=0;

        for(auto it:mp){
            if(it.second.size()>maxSize){
                maxSize=it.second.size();
                maxK=it.first;

                string temp="";
                for(auto c:it.second){
                    temp+=c;
                }
                res=temp;
            }
            else if(it.second.size()==maxSize && it.first>maxK){
                maxK=it.first;

                string temp="";
                for(auto c:it.second){
                    temp+=c;
                }
                res=temp;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<pair<string,string>> res;
        unordered_set<string> bl;
        bl.insert("electronics");
        bl.insert("grocery");
        bl.insert("pharmacy");
        bl.insert("restaurant");

        unordered_map<string,int> blOrder={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3},
        };
        
        for(int i=0;i<code.size();i++){
            if(!isActive[i]) continue;
            if(!bl.count(businessLine[i])) continue;

            string s=code[i];
            if(s.empty()) continue;
            bool isValid=true;
            for(int j=0;j<s.length();j++){
                char cur=s[j];
                if((cur>='a' && cur<='z') || (cur>='A'&&cur<='Z') || (cur>='0' &&cur<='9') || cur=='_'){
                    continue;
                }else{
                    isValid=false;
                    break;
                }
            }

            if(isValid){
                res.push_back({businessLine[i],s});
            }
        }

        // sort the res using custom operator
        sort(res.begin(),res.end(),[&](const pair<string,string>&a,const pair<string,string>&b){
            if(blOrder[a.first]!=blOrder[b.first]){
                return blOrder[a.first]<blOrder[b.first];
            }

            return a.second<b.second;
        });

        vector<string> finalRes;

        for(auto &it:res){
            finalRes.push_back(it.second);
        }

        return finalRes;
    }
};

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> noComm;

        for(auto &f:friendships){
            int f1=f[0];
            int f2=f[1];

            bool hasSameLang=false;

            for(auto l1:languages[f1-1]){
                for(auto l2:languages[f2-1]){
                    if(l1==l2){
                        hasSameLang=true;
                        break;
                    }
                }
            }

            if(hasSameLang) continue;

            noComm.insert(f1);
            noComm.insert(f2);
        }

        unordered_map<int,int> langCnt;
        // find the language among the users who cant communicate

        for(auto u:noComm){
            for(int l:languages[u-1]){
                langCnt[l]++;
            }
        }

        int maxSpoken=INT_MIN;
        int lanSpoken=-1;

        for(auto &it:langCnt){
            if(it.second>maxSpoken){
                maxSpoken=it.second;
                lanSpoken=it.first;
            }
        }

        if(maxSpoken==INT_MIN) return 0;
        int peopeToTrain=noComm.size()-maxSpoken;

        return peopeToTrain;
    }
};

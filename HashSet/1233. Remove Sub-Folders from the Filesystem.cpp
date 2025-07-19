// Time : O(nlogn) + O(n*m)
// space : O(n*m)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();

        sort(folder.begin(),folder.end());

        unordered_set<string>  vis;
        vector<string> res;
        for(string f:folder){
            int len=f.length();

            int lastSlash=0;
            for(int i=0;i<len;i++){
                if(f[i]=='/'){
                    lastSlash=i;
                }
            }

            string parent="";
            bool hasParent=false;
            for(int i=0;i<lastSlash;i++){

                if(f[i]=='/' && !parent.empty()){
                    if(vis.count(parent)){
                        hasParent=true;
                        break;
                    }
                }
                parent+=f[i];
            }

            if(vis.count(parent)){
                // edge cases like : /ad/af
                // the parent isnt checked inside the above for loop
                // so for the final parent needs to be checked here
                hasParent=true;
            }

            if(hasParent) continue;

            res.push_back(f);
            vis.insert(f);
        }

        return res;
    }
};

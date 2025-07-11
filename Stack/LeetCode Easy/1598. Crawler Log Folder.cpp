

// brute force: O(n) + space : o(n)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> folders;
        int n=logs.size();
        for(int i=0;i<n;i++){
            string cur=logs[i];

            if(cur=="../"){
                // remove the last sub folder if it exists
                if(folders.size()==0){
                    continue;
                }
                else{
                    folders.pop_back();
                }
            }
            else if(cur=="./"){
                // do nothing
                continue;
            }
            else{
                // put into folders; 
                folders.push_back(cur);
            }
        }

        return folders.size();
    }
};

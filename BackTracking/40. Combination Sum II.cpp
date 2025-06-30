class Solution {
private:
vector<vector<int>> res;
void createSum(int idx,vector<int>& candidates, int target,vector<int>&temp){

    if(target==0){
        res.push_back(temp);
        return;
    }

    for(int i=idx;i<candidates.size();i++){
        
        if(i>idx && candidates[i]==candidates[i-1]) continue;

        if(candidates[i]>target) break;

        temp.push_back(candidates[i]);
        createSum(i+1,candidates,target-candidates[i],temp);
        temp.pop_back();
    }
}    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp={};
        sort(candidates.begin(),candidates.end());
        createSum(0,candidates,target,temp);
        return res;
    }
};

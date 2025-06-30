class Solution {  
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int num=1;
        vector<int> temp={};
        createSum(num,k,n,temp);

        return res;
    }

    private:
    vector<vector<int>> res;

    void createSum(int num,int k,int target,vector<int>&temp){

        if(target==0 && temp.size()==k){
            res.push_back(temp);
            return;
        }

        for(int val=num;val<10;val++){

            if(val>target || temp.size()==k) break;

            temp.push_back(val);
            createSum(val+1,k,target-val,temp);
            temp.pop_back();
        }
    }
  
};

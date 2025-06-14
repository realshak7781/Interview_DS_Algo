class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int ops=0;
        while(i<n){
            bool isDuplicate=false;
            unordered_set<int> dup;

            for(int j=i;j<n;j++){
                if(dup.count(nums[j])){
                    isDuplicate=true;
                    break;
                }else{
                    dup.insert(nums[j]);
                }
            }

            if(!isDuplicate) return ops;

            i+=3;
            ops++;
        }

        return ops;
    }
};

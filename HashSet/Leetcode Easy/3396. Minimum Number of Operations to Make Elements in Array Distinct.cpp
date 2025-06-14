class Solution {
private:
int optimal(vector<int>&nums){
    int n=nums.size();
    unordered_set<int> st;

    for(int i=n-1;i>=0;i--){
        if(st.count(nums[i])){
            return ceil((i+1)/3.0);
        }
        else{
            st.insert(nums[i]);
        }
    }
    return 0;
}    
public:
    int minimumOperations(vector<int>& nums) {
        // int n=nums.size();

        // int i=0;
        // int ops=0;
        // while(i<n){
        //     bool isDuplicate=false;
        //     unordered_set<int> dup;

        //     for(int j=i;j<n;j++){
        //         if(dup.count(nums[j])){
        //             isDuplicate=true;
        //             break;
        //         }else{
        //             dup.insert(nums[j]);
        //         }
        //     }

        //     if(!isDuplicate) return ops;

        //     i+=3;
        //     ops++;
        // }

        // return ops;

        return optimal(nums);
    }
};

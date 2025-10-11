
class Solution {
TreeNode *solve(int low,int high,vector<int>&nums){

    if(low>high) return nullptr;

    int mid=low+(high-low)/2;
    int rootVal=nums[mid];

    TreeNode*root=new TreeNode(rootVal);

    root->left=solve(low,mid-1,nums);
    root->right=solve(mid+1,high,nums);

    return root;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};

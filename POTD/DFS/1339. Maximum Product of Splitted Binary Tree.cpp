// Time : O(n)
// space : O(N) worst case for recursion space stack

using ll=long long;
class Solution {
private:
const int mod=1e9+7;
int findTotalSum(TreeNode*root){
    if(!root) return 0;

    int curSum=root->val;
    curSum+=findTotalSum(root->left);
    curSum+=findTotalSum(root->right);

    return curSum;
}

int findMax(TreeNode*root,int totalSum,ll &maxSum){
    if(!root) return 0;

    ll leftSum=findMax(root->left,totalSum,maxSum);
    ll rightSum=findMax(root->right,totalSum,maxSum);
    ll curRootSum=(root->val+leftSum+rightSum);
    ll remSum=(totalSum-curRootSum);

    // trying to maximise the sum
    ll resMul=(curRootSum*remSum);
    maxSum=max(maxSum,resMul);

    return curRootSum;
}
public:
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        int totalSum=findTotalSum(root);

        ll maxSum=0;
        findMax(root,totalSum,maxSum);

        return maxSum%mod;
    }
};

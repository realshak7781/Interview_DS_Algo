


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time : O(n)
// space : O(n) recursion stack space in worst case for a skewed tree
class Solution {
private:
void solve(int curVal,TreeNode*root,int &totalSum){
    if(!root) return;
    if(!root->left && !root->right){
        int rootVal=root->val;
        curVal=curVal|rootVal;
        totalSum+=curVal;
        return;
    }

    curVal=curVal|root->val;
    solve(curVal<<1,root->left,totalSum);
    solve(curVal<<1,root->right,totalSum);
}
public:
    int sumRootToLeaf(TreeNode* root) {
        int totalSum=0;

        solve(0,root,totalSum);

        return totalSum;
    }
};

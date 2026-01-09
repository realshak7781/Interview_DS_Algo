// time : O(n)
// space : O(n) worst case due to recursion call stack
class Solution {
private:
pair<TreeNode*,int> solve(TreeNode*root){
    if(!root){
        return {nullptr,0};
    }
    if(!root->left && !root->right){
        return {root,1};
    }

    auto leftSide=solve(root->left);
    auto rightSide=solve(root->right);

    if(leftSide.second==rightSide.second){
        return {root,leftSide.second+1};
    }

    TreeNode*curRoot=nullptr;
    int dist;
    if(leftSide.second > rightSide.second){
        curRoot=leftSide.first;
        dist=leftSide.second+1;
    }
    else{
        curRoot=rightSide.first;
        dist=rightSide.second+1;
    }

    return {curRoot,dist};
}
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        TreeNode*ans=solve(root).first;
        return ans;
    }
};

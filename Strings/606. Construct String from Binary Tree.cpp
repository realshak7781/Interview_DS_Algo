// Time Complexity: O(n) - Each node is visited once
// Space Complexity: O(h) - h is the height of the tree (O(log n) for balanced, O(n) for skewed)
class Solution {
private:
string recur(TreeNode *root){
    if(!root) return "";
    //  base cases
    string res=to_string(root->val);
    string l=recur(root->left);
    string r=recur(root->right);

    if(!root->left && !root->right){
        return res;
    }
    if(!root->right){
        return res + "(" + l + ")";
    }
    if(!root->left){
        return res + "()" + "(" + r + ")";
    }

    return res + "(" + l + ")" + "(" + r + ")";
}    
public:
    string tree2str(TreeNode* root) {
        return recur(root);
    }
};

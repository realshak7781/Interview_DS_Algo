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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int curLevel=1;
        int maxLevelSum=INT_MIN;
        int minLevel=0;
        while(!q.empty()){
            int size=q.size();

            int curSum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                curSum+=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(curSum>maxLevelSum){
                maxLevelSum=curSum;
                minLevel=curLevel;
            }

            curLevel++;
        }

        return minLevel;
    }
};

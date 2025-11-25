#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
void getLeftNodes(TreeNode*root,vector<int>&result){
    if(!root) return;
    if(!root->left && !root->right) return;

    result.push_back(root->val);
    if(root->left){
        getLeftNodes(root->left,result);
    }
    else{
        getLeftNodes(root->right,result);
    }
}

void getLeafNodes(TreeNode *root,vector<int>&result){
    if(!root) return;
    if(!root->left && !root->right){
        result.push_back(root->val);
        return;
    }

    getLeafNodes(root->left,result);
    getLeafNodes(root->right,result);
}

void getRightNodes(TreeNode*root,vector<int>&result){
     if(!root) return;
    if(!root->left && !root->right) return;


    if(root->right){
        getLeftNodes(root->right,result);
    }
    else{
        getLeftNodes(root->left,result);
    }
    result.push_back(root->val);
}
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        // the logic is simple : push the root and then push the left side nodes and then push the right side nodes in reverse

        result.push_back(root->val);
        getLeftNodes(root->left,result);
        getLeafNodes(root->left,result); 
        getLeafNodes(root->right,result); 
        getRightNodes(root->left,result);
        return result;
    }
};

// ==========================================
// HELPER FUNCTIONS FOR TESTING
// ==========================================

// Constants to represent NULL in the input vector
const int NULL_NODE = INT_MIN;

// Helper to build a tree from a level-order vector (LeetCode style)
// Use INT_MIN to represent null nodes
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left child
        if (i < nodes.size()) {
            if (nodes[i] != NULL_NODE) {
                curr->left = new TreeNode(nodes[i]);
                q.push(curr->left);
            }
            i++;
        }
        
        // Right child
        if (i < nodes.size()) {
            if (nodes[i] != NULL_NODE) {
                curr->right = new TreeNode(nodes[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

// Helper to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Helper to run a single test case
void runTest(const vector<int>& inputNodes, const vector<int>& expected, int testId, string description) {
    Solution sol;
    TreeNode* root = buildTree(inputNodes);
    
    vector<int> actual = sol.boundaryOfBinaryTree(root);
    
    bool passed = (actual == expected);
    
    cout << "Test Case " << testId << ": " << description << endl;
    cout << "Input Tree (Level Order): ";
    printVector(inputNodes); // Note: INT_MIN shows as raw number, mentally replace with null
    cout << endl;
    
    if (passed) {
        cout << "✅ PASSED" << endl;
    } else {
        cout << "❌ FAILED" << endl;
        cout << "   Expected: "; printVector(expected); cout << endl;
        cout << "   Actual:   "; printVector(actual); cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    cout << "Running Boundary of Binary Tree Tests..." << endl;
    cout << "Note: " << NULL_NODE << " represents 'null' in input arrays." << endl;
    cout << "--------------------------------------------------" << endl;

    // Test Case 1: Example 1 from Problem
    // Input: 1, null, 2, 3, 4
    // Structure: 
    //   1
    //    \
    //     2
    //    / \
    //   3   4
    runTest({1, NULL_NODE, 2, 3, 4}, {1, 3, 4, 2}, 1, "Example 1 (Right subtree only)");

    // Test Case 2: Example 2 from Problem
    // Input: 1, 2, 3, 4, 5, 6, null, null, null, 7, 8, 9, 10
    runTest(
        {1, 2, 3, 4, 5, 6, NULL_NODE, NULL_NODE, NULL_NODE, 7, 8, 9, 10}, 
        {1, 2, 4, 7, 8, 9, 10, 6, 3}, 
        2, 
        "Example 2 (Complex Tree)"
    );

    // Test Case 3: Root only
    runTest({1}, {1}, 3, "Single Node");

    // Test Case 4: Left Boundary only
    //     1
    //    /
    //   2
    //  /
    // 3
    runTest({1, 2, NULL_NODE, 3}, {1, 2, 3}, 4, "Left Line Only");

    // Test Case 5: Left Zig-Zag (Testing definition of 'left-most')
    // Left boundary is defined by moving left if possible, else right.
    //      1
    //     /
    //    2
    //     \
    //      3
    //     /
    //    4
    // Path: 1 -> 2 -> 3 -> 4
    runTest({1, 2, NULL_NODE, NULL_NODE, 3, 4}, {1, 2, 3, 4}, 5, "Left Zig-Zag");

    // Test Case 6: Right Zig-Zag (Testing definition of 'right-most')
    // Right boundary is defined by moving right if possible, else left.
    //   1
    //    \
    //     2
    //    /
    //   3
    //    \
    //     4
    // Path: 1 -> 2 -> 3 -> 4 (Reverse for output: 1, 4, 3, 2)
    runTest({1, NULL_NODE, 2, 3, NULL_NODE, NULL_NODE, 4}, {1, 4, 3, 2}, 6, "Right Zig-Zag");

    // Test Case 7: Full 3-level tree
    //       1
    //    /     \
    //   2       3
    //  / \     / \
    // 4   5   6   7
    // Boundary: 1 (root), 2 (left), 4, 5, 6, 7 (leaves), 3 (right)
    runTest({1, 2, 3, 4, 5, 6, 7}, {1, 2, 4, 5, 6, 7, 3}, 7, "Full Binary Tree");

    return 0;
}

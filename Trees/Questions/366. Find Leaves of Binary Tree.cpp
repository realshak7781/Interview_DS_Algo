#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include<unordered_map>

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
unordered_map<int,vector<int>> adjList;
int dfs(TreeNode*root,vector<vector<int>> &result){
    if(!root) return -1;
    
    int leftHeight=dfs(root->left,result);
    int rightHeight=dfs(root->right,result);
    int curHeight=1+max(leftHeight,rightHeight);
    result[curHeight].push_back(root->val);

    return curHeight;
}

  int getHeight(TreeNode* root) {
        if (!root) return -1; // Base case: height of null is -1
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
         
        if(!root) return {};

         int size=getHeight(root);
         vector<vector<int>> result(size+1);
         dfs(root,result);
        return result;
    }
};

// ==========================================
// HELPER FUNCTIONS FOR TESTING
// ==========================================

// Constants to represent NULL in the input vector
const int NULL_NODE = INT_MIN;

// Helper to build a tree from a level-order vector
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

// Helper to print the result vector of vectors
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]";
}

// Test Runner
void runTest(const vector<int>& inputNodes, const vector<vector<int>>& expected, int testId, string description) {
    Solution sol;
    TreeNode* root = buildTree(inputNodes);
    
    cout << "Test Case " << testId << ": " << description << endl;
    
    vector<vector<int>> actual = sol.findLeaves(root);
    
    bool passed = (actual == expected);
    
    if (passed) {
        cout << "✅ PASSED" << endl;
    } else {
        cout << "❌ FAILED" << endl;
        cout << "   Expected: "; printResult(expected); cout << endl;
        cout << "   Actual:   "; printResult(actual); cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    cout << "Running Find Leaves of Binary Tree Tests..." << endl;
    cout << "--------------------------------------------------" << endl;

    // Test Case 1: Standard Example
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    // Order: [4,5,3] removed first, then [2], then [1]
    runTest(
        {1, 2, 3, 4, 5}, 
        {{4, 5, 3}, {2}, {1}}, 
        1, 
        "Standard Example"
    );

    // Test Case 2: Single Node
    // Tree: 1
    runTest(
        {1}, 
        {{1}}, 
        2, 
        "Single Node"
    );

    // Test Case 3: Skewed Left
    //     1
    //    /
    //   2
    //  /
    // 3
    // Order: [3] -> [2] -> [1]
    runTest(
        {1, 2, NULL_NODE, 3}, 
        {{3}, {2}, {1}}, 
        3, 
        "Left Skewed Line"
    );

    // Test Case 4: Uneven Levels
    //       1
    //      / \
    //     2   3
    //    / 
    //   4   
    // Leaves: 4 (depth 2), 3 (depth 1)
    // Wait, by definition we remove ALL leaves. 
    // Round 1: Leaves are 4 and 3.
    // Round 2: Leaf is 2.
    // Round 3: Leaf is 1.
    runTest(
        {1, 2, 3, 4}, 
        {{4, 3}, {2}, {1}}, 
        4, 
        "Uneven Levels"
    );

    return 0;
}

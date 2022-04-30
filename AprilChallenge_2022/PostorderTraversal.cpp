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

/*
Q145. Description: Given the root of a binary tree, return the postorder traversal of its nodes' values.
*/

class Solution {
public:
    // Recursive driver code to insert nodes into vector
    vector<int> postorderDriver(TreeNode* root, vector<int>& ans)
    {
        // Postorder = Left -> Right -> Data
        if(root == NULL)
            return ans;
        postorderDriver(root -> left, ans);
        postorderDriver(root -> right, ans);
        ans.push_back(root -> val);
        return ans;
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        return postorderDriver(root, ans);
    }
};
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
Q144. Description: Given the root of a binary tree, return the preorder traversal of its nodes' values.
*/

class Solution {
public:
    // Recursive driver code to insert nodes into vector
    vector<int> preorderDriver(TreeNode* root, vector<int>& ans)
    {
        // Preorder = Data -> Left -> Right
        if(root == NULL)
            return ans;
        ans.push_back(root -> val);
        preorderDriver(root -> left, ans);
        preorderDriver(root -> right, ans);
        return ans;
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        return preorderDriver(root, ans);
    }
};
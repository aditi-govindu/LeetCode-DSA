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
 Q112. Description: Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return false;

        // End of a path reached, check if value is expected one
        if(root->right == NULL && root->left == NULL)
            return root->val == targetSum;
        
        // Recursively check left and right subtrees
        return (hasPathSum(root -> left, targetSum - root -> val) || 
                hasPathSum(root->right, targetSum - root -> val));
    }
};
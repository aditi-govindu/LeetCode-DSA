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
Q226. Description: Given the root of a binary tree, invert the tree, and return its root.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        
        // Swap left and right nodes
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;

        // Recursively do this for left and right subtrees
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};
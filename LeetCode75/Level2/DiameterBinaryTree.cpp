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
Q543. Description: Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
*/

class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        int ldepth = height(root -> left);
        int rdepth = height(root -> right);
        
        int ldiameter = diameterOfBinaryTree(root -> left);
        int rdiameter = diameterOfBinaryTree(root -> right);
        
        return max(ldepth + rdepth, max(ldiameter, rdiameter));
    }
};
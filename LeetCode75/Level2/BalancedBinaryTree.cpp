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
Q110. Description: Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as: a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

class Solution {
public:
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && !(abs(depth(root->left) - depth(root->right)) > 1);
    }
};
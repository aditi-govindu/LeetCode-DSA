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
Q222. Description: Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/

class Solution {
public:
    int count = 0;
    void inOrder(TreeNode* root)
    {
        // Travel tree inorder and increment count when value seen
        if(root)
        {
            inOrder(root->left);
            count++;
            inOrder(root -> right);
        }
    }
    
    int countNodes(TreeNode* root) 
    {
        inOrder(root);
        return count;
    }
};
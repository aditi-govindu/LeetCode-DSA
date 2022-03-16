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
Q617. You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
        // Preorder traversal of trees, using Recursion
        root1 -> val = root1 -> val + root2 -> val;
        root1 -> left = mergeTrees(root1->left, root2->left);
        root1 -> right = mergeTrees(root1->right, root2->right); 
        // Add all nodes to tree 1 and return result
        return root1;
    }
};
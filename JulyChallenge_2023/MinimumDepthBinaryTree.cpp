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
 Q111. Description: Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
 */

class Solution {
public:
    int DFS(TreeNode* root)
    {
        // If node is a leaf, height is 0
        if(!root)
            return 0;
        // Recursively search non empty left and right subtrees
        if(!root -> left)
            return 1 + DFS(root -> right);
        if(!root -> right)
            return 1 + DFS(root -> left);
        // Minimum height is left and right trees + 1
        return 1 + min(DFS(root -> left), DFS(root -> right));
    }

    int minDepth(TreeNode* root) 
    {
        return DFS(root);
    }
};
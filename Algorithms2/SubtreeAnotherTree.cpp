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
Q572. Description: Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
*/

class Solution {
public:
    bool Same(TreeNode* t1, TreeNode* t2)
    {
        // Recursive function to check if root and subRoot are equal
        if(t1 == NULL && t2 == NULL)
            return true;
        if(t1 == NULL || t2 == NULL)
            return false;
        else if(t1 -> val != t2 -> val)
            return false;
        // Recursively check left and right subtrees
        return Same(t1 -> left, t2 -> left) && Same(t1 -> right, t2 -> right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;
        if(Same(root, subRoot))
            return true;
        // Check left side and right side of root tree
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
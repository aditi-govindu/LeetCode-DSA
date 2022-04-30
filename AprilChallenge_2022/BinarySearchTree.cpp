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
Q700. Description: You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL)
        {
            // Exact match found, return node
            if(root -> val == val)
                return root;
            // In BST, elements smaller than root are on the left
            else if (val < root -> val)
                root = root -> left;
            // Elements greater than root are on the right
            else
                root = root -> right;
        }
        // No match found, return empty list
        return NULL;
    }
};
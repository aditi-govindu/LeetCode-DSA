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
Q538. Description: Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
*/

class Solution {
private:
    int sum = 0;
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root != NULL)
        {
            // Add all nodes in right side, recursively
            convertBST(root -> right);
            sum += root -> val;
            root -> val = sum;
            // Add all nodes in left side, recursively
            convertBST(root -> left);
        }
        return root;
    }
};
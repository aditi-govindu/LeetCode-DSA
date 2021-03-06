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
Q230. Description: Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

class Solution {
public:
    int count = 0;
    int ans = 0;
    void inorder(TreeNode* root, int k)
    {
        if(root == NULL)
            return;
        inorder(root -> left, k);
        count++;
        if(count == k)
        {
            ans = root -> val;
            return;
        }
        inorder(root -> right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
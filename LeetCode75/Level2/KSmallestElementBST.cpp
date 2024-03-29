/*
Q230. Description: Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

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

class Solution {
public:
    int count = 0;
    int ans = 0;
    void InOrder(TreeNode* root, int k)
    {
        if(!root)
            return;
        InOrder(root -> left, k);
        count++;
        if(count == k)
        {
            ans = root -> val;
            return;
        }
        InOrder(root -> right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        InOrder(root, k);
        return ans;
    }
};
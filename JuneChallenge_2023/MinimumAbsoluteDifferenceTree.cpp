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
Q530. Description: Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
*/

class Solution 
{
public:
    vector<int> values;
    // Inorder traversal of BST gives sorted order by default. Save sorting time
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root -> left);
            values.push_back(root -> val);
            inorder(root -> right);
        }
    }

    int getMinimumDifference(TreeNode* root) 
    {
        inorder(root);
        int difference = INT_MAX;
        
        // Store minimum difference of adjacent elements
        for(int i = 1; i < values.size(); i++)
            difference = min(difference, values[i] - values[i - 1]);
        return difference;
    }
};
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
Q897. Description: Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
*/

class Solution {
public:
    // Inorder traversal of tree: left, Data, right
    void inorder(TreeNode* node, vector<int>& vals)
    {
        if(node == NULL)
            return;
        inorder(node -> left, vals);
        // Add nodes to vector
        vals.push_back(node -> val);
        inorder(node -> right, vals);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        // Initialize new tree to 0
        TreeNode* ans = new TreeNode(0);
        TreeNode* root2 = ans; 
        for(int i = 0; i < vals.size(); i++)
        {
            // Copy all nodes from vector onto new tree, right side
            root2 -> right = new TreeNode(vals[i]);
            root2 = root2 -> right;
        }
        return ans -> right;
    }
};
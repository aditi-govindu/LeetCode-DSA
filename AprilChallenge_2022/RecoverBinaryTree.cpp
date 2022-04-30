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
Q99. Description: You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
*/

class Solution {
public:
    TreeNode* firstMistake, *secondMistake, *pre;
    void recoverTree(TreeNode* root) 
    {
        // Swap nodes out of order in inorder traversal
        pre = new TreeNode(INT_MIN);
        inorder(root);
        swap(firstMistake->val, secondMistake->val);
    }
    
    void inorder(TreeNode* root) 
    {
	// Inorder traversal gives nodes in ascending order
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < pre->val)
			firstMistake = pre;
		if(firstMistake != nullptr && root->val < pre->val)
			secondMistake = root;
		pre = root;

		inorder(root->right);
	}
};
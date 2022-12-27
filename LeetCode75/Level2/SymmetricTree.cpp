/*
Q101. Description: Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 */
class Solution {
public:
    bool check(TreeNode* tree1, TreeNode* tree2)
    {
        if(!tree1 && !tree2)
            return true;
        if(tree1 && !tree2)
            return false;
        if(tree2 && !tree1)
            return false;
        if(tree1 -> val != tree2 -> val)
            return false;
        // Check for mirror images of each other: left = right and right = left
        return (check(tree1->left, tree2->right) && check(tree1->right, tree2->left));
    }
    bool isSymmetric(TreeNode* root) 
    {
        // If root is null or both children are null, tree is symmetric
        if(root == NULL)
            return true;
        if(!root -> right && !root -> left)
            return true;
        if(!root -> left && root -> right)
            return false;
        if(root -> left && !root -> right)
            return false;
        return check(root -> right, root -> left);
        
    }
};
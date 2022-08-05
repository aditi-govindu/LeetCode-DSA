/*
Q114. Description: Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 */

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
            return;
        
        flatten(root -> left);
        flatten(root -> right);
        
        if(root -> left)
        {
            TreeNode *right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            while(root -> right)
                root = root -> right;
            root -> right = right;
        }
    }
};
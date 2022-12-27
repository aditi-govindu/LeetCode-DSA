/* Q98. Description: Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
 */

class Solution {
public:
    bool TravelBST(TreeNode* root, long low, long high)
    {
        if(root == NULL)
            return true;
        if(root -> val > low && root -> val < high)
        {
            // Node is in range, check for left and right children
            return (TravelBST(root -> left, low, root -> val) && TravelBST(root -> right, root -> val, high));
        }
        else
            return false;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return TravelBST(root, LONG_MIN, LONG_MAX);
    }
};
/*Q236. Description: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 */

class Solution {
public:
    TreeNode* ans = NULL;
    int Traversal(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return 0;
        int left = Traversal(root -> left, p, q) ? 1 : 0;
        int right = Traversal(root -> right, p, q) ? 1 : 0;
        int mid = (root == p || root == q) ? 1 : 0;
        // If node is found in left = 1, right = 1, mid = 1 then return root itself
        if(mid + left + right >= 2)
            ans = root;
        // Else, search in left or right subtrees
        return (mid+left+right > 0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Traversal(root, p, q);
        return ans;
    }
};
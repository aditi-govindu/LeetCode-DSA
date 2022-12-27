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
 Q653. Description: Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
 */
 
class Solution {
public:
    vector<int> numbers;

    // Inorder traversal of array gives sorted list
    void inOrder(TreeNode* root)
    {
        if(root)
        {
            inOrder(root -> left);
            numbers.push_back(root -> val);
            inOrder(root -> right);
        }
    }

    bool findTarget(TreeNode* root, int k) 
    {
        inOrder(root);
        int start = 0;
        int end = numbers.size() - 1;
        
        while(start < end)
        {
            // Sum is last + first term
            int sum = numbers[start] + numbers[end];
            if(sum == k)
                return true;
            // If sum not equal to target, but smaller than it -> move start ahead
            else if(sum < k)
                start++;
            // If sum is greater, reduce end
            else
                end--;
        }
        return false;
    }
};
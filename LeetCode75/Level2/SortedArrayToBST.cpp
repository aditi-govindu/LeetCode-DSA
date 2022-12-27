/* Q108. Description: Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 */

class Solution {
public:
    TreeNode* ConvertToBST(vector<int>& nums, int start, int end)
    {
        // Insert nodes using binary search logic. Smaller on left, larger on right
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp -> left = ConvertToBST(nums, start, mid-1);
        temp -> right = ConvertToBST(nums, mid+1, end);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0) 
            return NULL;
        return ConvertToBST(nums,0,nums.size()-1);
    }
};
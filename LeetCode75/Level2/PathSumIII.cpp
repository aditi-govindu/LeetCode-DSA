/*
Q437. Description: Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/

class Solution {
public:
    int ans=0;
    void DFS(TreeNode* root,int sum,long long &curr)
    {
        if(root == NULL)
            return;
        curr += root -> val;  
        if(curr == sum)
            ans++;     
        DFS(root -> left, sum, curr);  
        DFS(root-> right, sum, curr);   
        curr -= root -> val;     //Backtracking 
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return 0;
        long long curr=0;
        DFS(root, targetSum, curr);
        pathSum(root -> left,targetSum);  
        pathSum(root -> right,targetSum);  
        return ans;
    }
};
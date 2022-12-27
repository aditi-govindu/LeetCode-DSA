/*
Q102. Description: Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {        
        vector<vector<int>> results;
        if(root == NULL)
            return results;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>level;
            int size = q.size();
            // Push all nodes in level to results
            for(int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                level.push_back(temp -> val);
            }
            results.push_back(level);
        }
        return results;
    }
};
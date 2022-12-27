/*
Q199. Description: Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root)
            return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            int ele;
            // Level wise traversal
            for(int i = 0; i < size; i++)
            {
                ele = q.front() -> val;
                if(q.front() -> left)
                    q.push(q.front() -> left);
                if(q.front() -> right)
                    q.push(q.front() -> right);
                q.pop();
            }
            // Answer is last element on every level during BFS
            ans.push_back(ele);
        }
        return ans;
    }
};
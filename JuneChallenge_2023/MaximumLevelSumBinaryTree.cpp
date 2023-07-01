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
Q1161. Description: Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/

class Solution {
public:
    vector<int> levelSum;

    int levelOrder(TreeNode* root)
    {
        int finalSum = INT_MIN;
        if(!root)
            return finalSum;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            // BFS traversal of tree
            int nodes = q.size();
            int curSum = 0;
            while(nodes > 0)
            {
                // Add node values, level wise and store in current sum
                TreeNode* temp = q.front();
                curSum += temp -> val;
                q.pop();

                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
                nodes--;
            }
            // Store sum per level and maximum sum seen so far
            levelSum.push_back(curSum);
            finalSum = max(finalSum, curSum);
        }
        return finalSum;
    }

    int maxLevelSum(TreeNode* root) 
    {
        // Get maximum sum of tree and check which level it is found at in the tree
        int ans = levelOrder(root);
        for(int i = 0; i < levelSum.size(); i++)
        {
            // Root is level 1, level 1 at level 2 and so on...
            if(ans == levelSum[i])
                return (i + 1);
        }
        return 0;
    }
};
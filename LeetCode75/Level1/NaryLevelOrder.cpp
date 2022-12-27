/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
Q429. Description: Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.
*/

class Solution {
public:    
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> results;
        if(root == NULL)
            return results;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int row = q.size();
            vector<int> level;
            
            for(int i = 0; i < row; i++)
            {
                // Add node at front of queue to result
                Node* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                
                int kids = (temp -> children).size();
                
                // Push all non null children to queue
                for(int c = 0; c < kids; c++)
                    if(temp -> children[c] != NULL) q.push(temp -> children[c]);
            }
            // Add all nodes at the level into result
            results.push_back(level);
        }
        return results;
    }
};
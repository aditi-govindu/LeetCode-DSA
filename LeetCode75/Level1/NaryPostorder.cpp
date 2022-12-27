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
Q590. Description: Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value.
*/

class Solution {
public:
    void helper(Node* root, vector<int>& results)
    {
        // Explore all children, then push nodes of children into result
        for(int i = 0; i < root->children.size(); i++)
            helper(root->children[i], results);
        results.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) 
    {
        vector<int> results;
        if(root == NULL)
            return results;
        helper(root, results);
        return results;
    }
};
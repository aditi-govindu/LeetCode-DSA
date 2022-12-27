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
Q589. Description: Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value
*/

class Solution {
public:
    void helper(Node* root, vector<int>& results)
    {
        // Push value into tree. Explore children, 1 at a time
        results.push_back(root -> val);
        vector<Node*> kids = root -> children;
        for(int i = 0; i < kids.size(); i++)
            helper(root->children[i], results);
    }
    
    vector<int> preorder(Node* root) 
    {
        vector<int>results;
        if(root == NULL)
            return results;
        helper(root, results);
        return results;
    }
};
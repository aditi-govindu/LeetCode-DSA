/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
Q116. Description: You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node*> q;
        // BFS traversal of tree using queue
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0 ; i < size ; i++)
            {
                Node* item = q.front(); 
                // Last item in queue implies last node in level, next is set to NULL
                if(size - 1 == i)
                    item -> next = NULL;
                q.pop();
                // Add items to queue, levelwise
                if(size - 1 != i)
                    item -> next = q.front();
                if(item -> left != NULL)
                    q.push(item -> left);
                if(item -> right != NULL)
                    q.push(item -> right);
            }
        }
        return root;
    }
};
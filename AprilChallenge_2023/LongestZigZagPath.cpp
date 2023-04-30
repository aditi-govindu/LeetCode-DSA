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
 Q1372. Description: You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
 */
 
class Solution {
public:
    int pathLength = 0;
    void DFS(TreeNode* node, bool goLeft, int steps)
    {
        if(!node)
            return;
        pathLength = max(pathLength, steps);
        if(goLeft)
        {
            DFS(node -> left, false, steps+1);
            DFS(node -> right, true, 1);
        }
        else
        {
            DFS(node -> left, false, 1);
            DFS(node -> right, true, steps+1);
        }
    }

    int longestZigZag(TreeNode* root) 
    {
        DFS(root, false, 0);
        DFS(root, true, 0);
        return pathLength;
        
    }
};
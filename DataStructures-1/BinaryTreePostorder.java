/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 // Q145. Description: Binary tree postorder traversal
class Solution {
    List<Integer> results = new ArrayList<Integer>();
    public List<Integer> postorderTraversal(TreeNode root) 
    {
        if(root != null)
        {
            postorderTraversal(root.left);
            postorderTraversal(root.right);
            results.add(root.val);
        }
        return results;
    }
}
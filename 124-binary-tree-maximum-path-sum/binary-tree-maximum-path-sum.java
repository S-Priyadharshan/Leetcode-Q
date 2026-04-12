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
class Solution {
    int maxsum=Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if(root==null)return 0;
        maxgain(root);
        return maxsum;
    }
    public int maxgain(TreeNode root){
        if(root==null)return 0;
        int leftgain=Math.max(maxgain(root.left),0);
        int rightgain=Math.max(maxgain(root.right),0);
        maxsum=Math.max(maxsum,root.val+leftgain+rightgain);
        return root.val+Math.max(leftgain,rightgain);
    }
}
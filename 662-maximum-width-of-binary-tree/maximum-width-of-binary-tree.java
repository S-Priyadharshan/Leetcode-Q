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
    class Pair{
        TreeNode node;
        int index;
        Pair(TreeNode node,int index){
            this.node=node;
            this.index=index;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        if(root==null)return 0;
        Queue<Pair> q=new LinkedList<>();
        q.offer(new Pair(root,0));
        int maxwidth=0;
        while(!q.isEmpty()){
            int len=q.size();
            int start=q.peek().index;
            int index=start;
            for(int i=0;i<len;i++){
                Pair p=q.poll();
                TreeNode node=p.node;
                index=p.index;
                if(node.left!=null){
                    q.offer(new Pair(node.left,2*index));
                }
                if(node.right!=null){
                    q.offer(new Pair(node.right,2*index+1));
                }
            }
            maxwidth=Math.max(maxwidth,index-start+1);
        }
        return maxwidth;
    }
}
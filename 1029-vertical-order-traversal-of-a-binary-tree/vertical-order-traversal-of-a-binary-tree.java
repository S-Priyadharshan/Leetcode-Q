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
    public class Node{
        int val,row,col;
        public Node(int val,int row,int col){
            this.val=val;
            this.row=row;
            this.col=col;
        }
    }
    List<Node> tree=new ArrayList<>();
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        if(root==null)return new ArrayList<>();
        dfs(root,0,0);
        Collections.sort(tree,(a,b)->{
            if(a.col!=b.col)return a.col-b.col;
            if(a.row!=b.row)return a.row-b.row;
            return a.val-b.val;
        });
        List<List<Integer>> res=new ArrayList<>();
        int prevCol=Integer.MIN_VALUE;
        for(Node n:tree){
            if(n.col!=prevCol){
                res.add(new ArrayList<>());
                prevCol=n.col;
            }
            res.get(res.size()-1).add(n.val);
        }
        return res;
    }
    public void dfs(TreeNode root,int row,int col){
        if(root==null)return;
        tree.add(new Node(root.val,row,col));
        dfs(root.left,row+1,col-1);
        dfs(root.right,row+1,col+1);
    }
}
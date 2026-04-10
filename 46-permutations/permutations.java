class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        int n=nums.length;
        boolean[] vis=new boolean[n];
        permutations(nums,vis,n,res,new ArrayList<>());
        return res;
    }
    public void permutations(int[] nums,boolean[] vis,int n,List<List<Integer>> res,
    List<Integer> curr){
        if(curr.size()==n){
            res.add(new ArrayList<>(curr));
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
             vis[i]=true;
             curr.add(nums[i]);
             permutations(nums,vis,n,res,curr);
             vis[i]=false;
             curr.remove(curr.size()-1);   
            }
        }
    }
}
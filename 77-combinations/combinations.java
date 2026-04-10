class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res=new ArrayList<>();
        combinations(res,n,k,new ArrayList<>(),1);
        return res;
    }
    public void combinations(List<List<Integer>> res,int n,int k,List<Integer> curr,int s){
        if(curr.size()==k){
            res.add(new ArrayList<>(curr));
            return;
        }
        for(int i=s;i<=n;i++){
            curr.add(i);
            combinations(res,n,k,curr,i+1);
            curr.remove(curr.size()-1);
        }
    }
}